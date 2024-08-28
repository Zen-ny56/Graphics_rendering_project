/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:11:39 by naadam            #+#    #+#             */
/*   Updated: 2024/08/28 15:28:13 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_circle(t_window *w, int center_x, int center_y, int radius, int color)
{
	int x;
	int	y;
	int radius_squared;

	radius_squared = radius * radius;
	y = -radius;
	while (y <= radius)
    {
		x = -radius;
        while (x <= radius)
        {
			if ((x * x) + (y * y) <= radius_squared)
				my_mlx_pixel_put(w, center_x + x, center_y + y, color);
			x++;
        }
		y++;
    }
}

void draw_player(t_window *w, t_player *player, int tile_size)
{
    int radius;

	radius = tile_size / 4;
    draw_circle(w, (int)player->pos_x, (int)player->pos_y, radius, 0xFF0000);
}

void    mark_player(t_data *data, int x, int y, int tile_size)
{
	int player_size;
	int color;

	player_size = 1;
	color = 0xFF0000;
	data->player = malloc(sizeof(t_player));
 	data->player->pos_x = (x * tile_size) + (tile_size / 2.0);
    data->player->pos_y = (y * tile_size) + (tile_size / 2.0);
	if (data->map->layout[y][x] == 'E')
		data->player->angle = 0;
	if (data->map->layout[y][x] == 'N')
		data->player->angle = PI / 2;
	else if (data->map->layout[y][x] == 'W')
		data->player->angle = PI;
	else if (data->map->layout[y][x] == 'S')
		data->player->angle = 3 * PI / 2;
	data->map->layout[y][x] = '0';
}