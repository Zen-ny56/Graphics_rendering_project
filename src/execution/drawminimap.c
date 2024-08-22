/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:39:57 by naadam            #+#    #+#             */
/*   Updated: 2024/08/22 18:40:56 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_square(t_window *w, int x, int y, int color, int tile_size)
{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < tile_size; j++)
        {
            my_mlx_pixel_put(w, x + i / 1.10, y + j / 1.10, color);
        }
    }
}


void	set_win_values(t_window *ups, t_data *m)
{
	ups->mlx = mlx_init();
	if (!ups->mlx)
		error_message(0, m);
	ups->window = mlx_new_window(ups->mlx, 800, 800, "Mini-Map");
	if (!ups->window)
		error_message(0, m);
	ups->img = mlx_new_image(ups->mlx, 800, 800);
	if (!ups->img)
		error_message(0, m);
	ups->addr = mlx_get_data_addr(ups->img, &ups->bits_per_pixel, &ups->line_len, &ups->endian);
	if (!ups->addr)
		error_message(0, m);
}

void    draw(t_data *m, t_map *map, t_cur *cur, t_parse *p, int tile_size)
{
	(void)m;
	cur->y = 0;
	while (cur->y < p->rows)
	{
		cur->x = 0;
		while (cur->x < p->max)
		{
			if (map->layout[cur->y][cur->x] == '1')
				draw_square(m->window, (cur->x * tile_size), (cur->y * tile_size), 0x0000FF, tile_size);
			else if (map->layout[cur->y][cur->x] == '0' || map->layout[cur->y][cur->x] == 'F')
				draw_square(m->window, (cur->x * tile_size), (cur->y * tile_size), 0x000000, tile_size);
			 cur->x++;
		}
		cur->y++;
	}
}

int calculatetilesize(int window_dimension, int map_dimension)
{
    return (window_dimension / map_dimension);
}

void    draw_minimap(t_data *m)
{
	int	tile_size;
	int	j;
	int	k;
	
	// j = -1;
	// while (m->map->layout[++j])
	// 	printf("%s\n",m->map->layout[j]);
	// printf("%d %d\n", m->parse->max, m->parse->rows);
	// exit(0);
	m->window = malloc(sizeof(t_window));
	set_win_values(m->window, m);
	k = calculatetilesize(800, m->parse->max);
	j = calculatetilesize(800, m->parse->rows - 1);
	if (k < j)
		tile_size = k;
	else
		tile_size = j;
	draw(m, m->map, m->cur, m->parse, tile_size);
	mlx_put_image_to_window(m->window->mlx, m->window->window, m->window->img, 0, 0);
	mlx_loop(m->window->mlx);
}