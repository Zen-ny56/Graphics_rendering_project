/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:39:57 by naadam            #+#    #+#             */
/*   Updated: 2024/09/05 14:16:33 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_square(t_window *w, t_cur *cur, t_parse *p, int color) // Will norminette this
{
    int i, j;
    int x, y;
    x = (cur->x * p->tile_size) + 1;
    y = (cur->y * p->tile_size) + 1;
    // Draw the tile
    for (i = 0; i < p->tile_size; i++)
    {
        for (j = 0; j < p->tile_size; j++)
        {
            my_mlx_pixel_put(w, x + j, y + i, color);
        }
    }
	// Draw the border (optional, adjust thickness if needed)
    for (i = 0; i < p->tile_size; i++)
    {
        // Top border
        my_mlx_pixel_put(w, x + i, y, 0x000000);
        // Bottom border
        my_mlx_pixel_put(w, x + i, y + p->tile_size - 1, 0x000000);
    }
    for (j = 0; j < p->tile_size; j++)
    {
        // Left border
        my_mlx_pixel_put(w, x, y + j, 0x000000);
        // Right border
        my_mlx_pixel_put(w, x + p->tile_size - 1, y + j, 0x000000);
    }
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
	ups->addr = mlx_get_data_addr(ups->img, &ups->bits_per_pixel, &ups->line_len, &ups->endian);
	if (!ups->addr)
		error_message(0, m);
}

void    draw(t_data *m, t_map *map, t_cur *cur, t_parse *p)
{
	char	**t;

	cur->y = 0;
	t = map->layout;
	while (cur->y < p->rows)
	{
		cur->x = 0;
		while (cur->x <= p->max)
		{
			if (t[cur->y][cur->x] == '1')
				draw_square(m->window, cur, p, 0x0000FF);
			else if (t[cur->y][cur->x] == '0')
				draw_square(m->window, cur, p, 0x000000);
			else if (t[cur->y][cur->x] == 'N' || t[cur->y][cur->x] == 'S'
				|| t[cur->y][cur->x] == 'E' || t[cur->y][cur->x] == 'W')
			{
				draw_square(m->window, cur, p, 0x000000);
				mark_player(m, cur->x, cur->y, p);
			}
			cur->x++;
		}
		cur->y++;
	}
}

int calculatetilesize(int window_dimension, int map_dimension)
{
    return (window_dimension / map_dimension) - 1;
}

void	set_tilesize(t_parse *parse) //Set the size of the tiles
{
	int k;
	int	j;
	
	k = calculatetilesize(M_WIDTH, parse->max);
	j = calculatetilesize(M_HEIGHT, parse->rows);
	if (k < j)
		parse->tile_size = k;
	else
		parse->tile_size = j;
}

void    draw_grid(t_data *m)
{
	set_win_values(m->window, m);
	set_tilesize(m->parse);
	draw(m, m->map, m->cur, m->parse);
}

