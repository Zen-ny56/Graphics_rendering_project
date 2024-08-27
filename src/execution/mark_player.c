/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:11:39 by naadam            #+#    #+#             */
/*   Updated: 2024/08/27 20:43:27 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    mark_player(t_data *data, int x, int y)
{
	int player_size;
	int color;

	player_size = 1;
	color = 0xFF0000;
	data->player = malloc(sizeof(t_player));
	data->player->pos_x = x * 64.00 + 32.00;
	data->player->pos_y = y * 64.00 + 32.00;
	if (data->map->layout[y][x] == 'E')
		data->player->angle = 0;
	if (data->map->layout[y][x] == 'N')
		data->player->angle = PI / 2;
	else if (data->map->layout[y][x] == 'W')
		data->player->angle = PI;
	else if (data->map->layout[y][x] == 'S')
		data->player->angle = 3 * PI / 2;
	data->map->layout[y][x] = '0';
	draw_player(data, data->window, player_size, color);	
}