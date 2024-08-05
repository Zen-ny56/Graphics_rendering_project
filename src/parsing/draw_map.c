/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:49:37 by naadam            #+#    #+#             */
/*   Updated: 2024/08/05 20:30:50 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_data *main)
{
	unsigned int y;
	unsigned int x;
	int color = 0;
	unsigned int py;
	unsigned int px;
	unsigned int cell_width = main->window->width / main->map->width;
    unsigned int cell_height = main->window->height / main->map->height;
	y = -1;
	while (++y < main->map->height)
	{
		x = -1;
		while (++x < main->map->width)
		{
			if (main->map->layout[y][x] == '1')
			{
				printf("%d\n" ,main->map->layout[y][x]);
				color = 0xFFFFFF;
			}
			else if (main->map->layout[y][x] == '0')
			{
				printf("%d\n" ,main->map->layout[y][x]);
				color = 0x000000;
			}
			else if (main->map->layout[y][x] == 'N' || main->map->layout[y][x] == 'S'
				|| main->map->layout[y][x] == 'E' || main->map->layout[y][x] == 'W')
				color = 0xFF0000;
			else
				continue ;
		}
		py = -1;
		while (++py < cell_height)
		{
			px = -1;
			while (++px < cell_width)
				my_mlx_pixel_put(main->window, x * cell_width + px, y * cell_height + py, color);
		}
	}
}
