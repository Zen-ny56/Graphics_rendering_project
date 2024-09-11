/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windonhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:25 by naadam            #+#    #+#             */
/*   Updated: 2024/09/10 23:11:25 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	redraw(t_data *m)
{
	mlx_clear_window(m->window->mlx, m->window->window);
	set_tilesize(m->parse);
	draw(m, m->map, m->cur, m->parse);
	draw_player(m->window, m->player, m->parse->tile_size);
	// set_plane(m->player);
	set_raydir(m->player, m->window, m);
	mlx_put_image_to_window(m->window->mlx, m->window->window, m->window->img, 0, 0);	
}

int	basic_movement(int keycode, t_player *player, t_data *m)
{
	double	new_x;
	double	new_y;

	new_x = player->pos_x;
	new_y = player->pos_y;
	if (keycode == 13)
	{
		new_x += player->dir_x * MOVE_SPEED;
		new_y += player->dir_y * MOVE_SPEED;
	}
	else if (keycode == 0)
	{
		new_x -= player->dir_y * MOVE_SPEED;
		new_y += player->dir_x * MOVE_SPEED;
	}
	else if (keycode == 1)
	{
		new_x -= player->dir_x * MOVE_SPEED;
		new_y -= player->dir_y * MOVE_SPEED;
	}
	else if (keycode == 2)
	{
		new_x += player->dir_y * MOVE_SPEED;
		new_y -= player->dir_x * MOVE_SPEED;
	}
	check_collision(m, new_x, new_y);
	printf("%f %f %f\n", player->pos_x, player->pos_x, player->perpWallDist);
	redraw(m);
	return (0);
}

int	exit_window(t_data *m)
{
	mlx_clear_window(m->window->mlx, m->window->window);
	mlx_destroy_window(m->window->mlx, m->window->window);
	free_and_exit(m, 0);
	ft_putstr_fd("Window exited\n", 1);
	return (0);
}

void	change_plane(t_player *player, double angle)
{
	double	old_plane_x;

	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	change_direction(t_player *player, double angle)
{
	double old_dir_x;

	old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
}

void	rotate(t_player *player, double angle, t_data *m)
{
	change_direction(player, angle);
	change_plane(player, angle);
	redraw(m);
}

int	keypress(int keycode, t_data *m)
{
	if (keycode == 53)
	{
		if (!exit_window(m))
			exit(0);
	}
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		basic_movement(keycode, m->player, m);
	if (keycode == 123)
		rotate(m->player, PI / 12, m);
	if (keycode == 124)
		rotate(m->player, (-1) * (PI / 12), m);
	return (0);
}
