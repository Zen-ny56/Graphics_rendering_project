/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:03 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 20:49:57 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_plane(t_player *player)
{
	player->plane_length = tan(PI / 6);
	player->plane_x = player->dir_y * player->plane_length;
	player->plane_y = (player->dir_x * -1) * player->plane_length;
}

void	set_direction(t_player *player)
{
	if (player->angle == 0)
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (player->angle == PI / 2)
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (player->angle == PI)
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (player->angle == 3 * PI / 2)
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
}

void	cal_side(t_player *player, t_map *map)
{
	map->mapx = (int)player->pos_x;
	map->mapy = (int)player->pos_y;
	if (player->raydir_x < 0)
	{
		player->stepx = -1;
		player->sidedistx = (player->pos_x - map->mapx);
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (map->mapx + 1.0 - player->pos_x);
	}
	if (player->raydir_y < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->pos_y - map->mapy);
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (map->mapy + 1.0 - player->pos_y);
	}
}

void	draw_ray(t_window *w, t_player *player, int color)
{
	double	current_x;
	double	current_y;
	double	distance_remaining;

	current_x = player->pos_x;
	current_y = player->pos_y;
	distance_remaining = player->perpwalldist;
	while (distance_remaining > 0)
	{
		my_mlx_pixel_put(w, (int)current_x, (int)current_y, color);
		current_x += player->raydir_x;
		current_y += player->raydir_y;
		distance_remaining -= 1;
	}
}

void	performdda(t_player *player, t_map *map, t_parse *p)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{
			player->sidedistx += player->deltadistx;
			map->mapx += player->stepx;
			player->side = 0;
		}
		else
		{
			player->sidedisty += player->deltadisty;
			map->mapy += player->stepy;
			player->side = 1;
		}
		if (map->layout[map->mapy / p->tile_size]
			[map->mapx / p->tile_size] == '1')
			hit = 1;
	}
}
