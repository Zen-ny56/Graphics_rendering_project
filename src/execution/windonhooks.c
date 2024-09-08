/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windonhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:25 by naadam            #+#    #+#             */
/*   Updated: 2024/09/08 19:43:31 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_collision(t_data *m, double new_x, double new_y)
{
	t_player *pl = m->player;
	int		t = m->parse->tile_size;

	// Calculate the future tile position of the player
	int map_x = (int)(new_x / t);
	int map_y = (int)(new_y / t);

	// Check collision for the new position
	if (m->map->layout[map_y][map_x] != '1') // If the new position is not a wall
	{
		pl->pos_x = new_x;
		pl->pos_y = new_y;
	}
	// Else: if it's a wall, do nothing and retain the old position
}

void	redraw(t_data *m)
{
	mlx_clear_window(m->window->mlx, m->window->window);
	set_tilesize(m->parse);
	draw(m, m->map, m->cur, m->parse);
	draw_player(m->window, m->player, m->parse->tile_size);
	set_raydir(m->player, m->window, m);
	mlx_put_image_to_window(m->window->mlx, m->window->window, m->window->img, 0, 0);	
}

// int	basic_movement(int keycode, t_player *player, t_data *m)
// {
// 	double	original_x = player->pos_x;
// 	double	original_y = player->pos_y;
// 	if (keycode == 13)
// 	{	
// 		player->pos_x += player->dir_x * MOVE_SPEED;
// 		player->pos_y += player->dir_y * MOVE_SPEED;
// 	}
// 	else if (keycode == 0)
// 	{
// 		player->pos_x -= player->dir_y * MOVE_SPEED;
// 		player->pos_y += player->dir_x * MOVE_SPEED;
// 	}
// 	else if (keycode == 1)
// 	{
// 		player->pos_x -= player->dir_x * MOVE_SPEED;
// 		player->pos_y -= player->dir_y * MOVE_SPEED;
// 	}
// 	else if (keycode == 2)
// 	{
// 		player->pos_x += player->dir_y * MOVE_SPEED;
// 		player->pos_y -= player->dir_x * MOVE_SPEED;
// 	}
// 	check_collision(m, original_x, original_y);
// 	redraw(m);
// 	return (0);
// }

int	basic_movement(int keycode, t_player *player, t_data *m)
{
	double	new_x = player->pos_x;
	double	new_y = player->pos_y;

	if (keycode == 13) // Move forward
	{	
		new_x += player->dir_x * MOVE_SPEED;
		new_y += player->dir_y * MOVE_SPEED;
	}
	else if (keycode == 0) // Move left
	{
		new_x -= player->dir_y * MOVE_SPEED;
		new_y += player->dir_x * MOVE_SPEED;
	}
	else if (keycode == 1) // Move backward
	{
		new_x -= player->dir_x * MOVE_SPEED;
		new_y -= player->dir_y * MOVE_SPEED;
	}
	else if (keycode == 2) // Move right
	{
		new_x += player->dir_y * MOVE_SPEED;
		new_y -= player->dir_x * MOVE_SPEED;
	}

	// Call collision check with the new position
	check_collision(m, new_x, new_y);
	redraw(m);
	return (0);
}

int exit_window(t_data *m) // Exit window
{
	mlx_clear_window(m->window->mlx, m->window->window);
	mlx_destroy_window(m->window->mlx, m->window->window);
	free_and_exit(m, 0);
	ft_putstr_fd("Window exited\n", 1);
	return (0);
}

void	change_plane(t_player *player, double angle) // Change the camera plane
{
	double old_plane_x;

	old_plane_x = player->plane_x;
    player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
    player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	change_direction(t_player *player, double angle) // Direction of the player has been changed
{
	double old_dir_x;

	old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
}

void	rotate(t_player *player, double angle, t_data *m) // Handle rotation
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