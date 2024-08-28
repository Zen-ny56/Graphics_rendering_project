/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windonhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:25 by naadam            #+#    #+#             */
/*   Updated: 2024/08/28 18:49:01 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	basic_movement(int keycode, t_player *player)
{
	if (keycode == 13)
	{	
		player->pos_x += player->dir_x * MOVE_SPEED;
		player->pos_y += player->dir_y * MOVE_SPEED;
	}
	else if (keycode == 0)
	{
		player->pos_x -= player->dir_y * MOVE_SPEED;
		player->pos_y += player->dir_x * MOVE_SPEED;
	}
	else if (keycode == 1)
	{
		player->pos_x -= player->dir_x * MOVE_SPEED;
		player->pos_y -= player->dir_y * MOVE_SPEED;
	}
	else if (keycode == 2)
	{
		player->pos_x += player->dir_y * MOVE_SPEED;
		player->pos_y -= player->dir_x * MOVE_SPEED;
	}
	//Call draw player function
	//Add tile_size to parsing structure
}

int exit_window(t_window *win)
{
	mlx_clear_window(win->mlx, win->window);
	mlx_destroy_window(win->mlx, win->window);
	exit(0);
	ft_putstr_fd("Window exited\n", 1);
	return (0);
}

void	rotate(int keycode, t_player *player, double angle)
{
	double old_dir_x = player->dir_x;
	double cos_theta = cos(angle);
	double sin_theta = sin(angle);
	player->dir_x = player->dir_x * cos_theta - player->dir_y * sin_theta;
	player->dir_y = old_dir_x * sin_theta + player->dir_y * cos_theta;
}
int	keypress(int keycode, t_window *win, t_data *m)
{
	(void)m;
	if (keycode== 53)
	{
		if (!exit_window(win))
			exit(0);
	}
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		basic_movement(keycode, m->player);
	if (keycode == 123)
		rotate(keycode, m->player, PI / 12);
	if (keycode == 124)
		rotate(keycode, m->player, (-1) * (PI / 12));
	return (0);
}