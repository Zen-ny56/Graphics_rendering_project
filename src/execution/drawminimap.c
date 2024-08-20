/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:39:57 by naadam            #+#    #+#             */
/*   Updated: 2024/08/20 21:24:58 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_square(t_window *w, int x, int y, int color, int tile_size)
{
    int i, j;

    for (i = 0; i < tile_size; i++)
    {
        for (j = 0; j < tile_size; j++)
        {
            mlx_pixel_put(w->mlx, w->window, x + i, y + j, color);
        }
    }
}


void	set_win_values(t_window *ups, t_data *m)
{
	ups->mlx = mlx_init();
	if (!ups->mlx)
		error_message(0, m);
	ups->addr = NULL;
	ups->window = mlx_new_window(ups->mlx, 800, 600, "Mini-Map");
	if (!ups->window)
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
				draw_square(m->window, cur->x * tile_size, cur->y * tile_size, 0x000000, tile_size);
			else if (map->layout[cur->y][cur->x] == '0' || map->layout[cur->y][cur->x] == 'F')
				draw_square(m->window, cur->x * tile_size, cur->y * tile_size, 0x0000FF, tile_size);
			cur->x++;
		}
		cur->y++;
	}
}

int calculatetilesize(int window_dimension, int map_dimension)
{
    return window_dimension / map_dimension;
}

void    draw_minimap(t_data *m)
{
	int	tile_size;
	int	j;
	int	k;
	
	m->window = malloc(sizeof(t_window));
	set_win_values(m->window, m);
	k = calculatetilesize(800, m->parse->max);
	j = calculatetilesize(600, m->parse->rows);
	if (k < j)
		tile_size = k;
	else
		tile_size = j;
	draw(m, m->map, m->cur, m->parse, tile_size);
	mlx_loop(m->window->mlx);
}