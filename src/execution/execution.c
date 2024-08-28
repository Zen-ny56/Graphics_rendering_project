/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:03 by naadam            #+#    #+#             */
/*   Updated: 2024/08/28 19:07:09 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_plane(t_player *player)
{
	player->plane_x = player->dir_y * player->plane_length;
	player->plane_y = player->dir_x * player->plane_length;
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

void    execution(t_data *main)
{
	draw_minimap(main);
	set_direction(main->player);
	main->player->plane_length = tan(PI / 6);
	set_plane(main->player);
	//Set loop to create rays through intersections
	mlx_loop(main->window->mlx);
} 