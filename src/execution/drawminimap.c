/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:39:57 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 20:20:57 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_filled_square(t_data *m, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->parse->tile_size)
	{
		j = 0;
		while (j < m->parse->tile_size)
			my_mlx_pixel_put(m->window, x + j++, y + i, color);
		i++;
	}
}

void	draw_square_border(t_data *m, int x, int y, int tile_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < tile_size)
	{
		my_mlx_pixel_put(m->window, x + i, y, 0x000000);
		my_mlx_pixel_put(m->window, x + i, y + tile_size - 1, 0x000000);
		i++;
	}
	j = 0;
	while (j < tile_size)
	{
		my_mlx_pixel_put(m->window, x, y + j, 0x000000);
		my_mlx_pixel_put(m->window, x + tile_size - 1, y + j++, 0x000000);
	}
}

void	draw_square(t_data *m, t_cur *cur, t_parse *p, int color)
{
	int	x;
	int	y;

	x = (cur->x * p->tile_size) + 1;
	y = (cur->y * p->tile_size) + 1;
	draw_filled_square(m, x, y, color);
	draw_square_border(m, x, y, p->tile_size);
}

void	set_win_values(t_window *ups, t_data *m)
{
	ups->mlx = mlx_init();
	if (!ups->mlx)
		error_message(0, m);
	ups->window = mlx_new_window(ups->mlx, M_WIDTH, M_HEIGHT, "Mini-Map");
	if (!ups->window)
		error_message(0, m);
	ups->img = mlx_new_image(ups->mlx, M_WIDTH, M_HEIGHT);
	if (!ups->img)
		error_message(0, m);
	ups->addr = mlx_get_data_addr(ups->img, &ups->bits_per_pixel,
			&ups->line_len, &ups->endian);
	if (!ups->addr)
		error_message(0, m);
}
