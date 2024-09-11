/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windonhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:25 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 22:22:08 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	redraw(t_data *m)
{
	mlx_clear_window(m->window->mlx, m->window->window);
	set_tilesize(m->parse);
	draw(m, m->map, m->cur, m->parse);
	draw_player(m->window, m->player, m->parse->tile_size);
	set_raydir(m->player, m->window, m);
	mlx_put_image_to_window(m->window->mlx, m->window->window,
		m->window->img, 0, 0);
}

void	calculate_new_position(int keycode, t_player *p, double *nx, double *ny)
{
	*nx = p->pos_x;
	*ny = p->pos_y;
	if (keycode == 13)
	{
		*nx += p->dir_x * MOVE_SPEED;
		*ny += p->dir_y * MOVE_SPEED;
	}
	else if (keycode == 0)
	{
		*nx -= p->dir_y * MOVE_SPEED;
		*ny += p->dir_x * MOVE_SPEED;
	}
	else if (keycode == 1)
	{
		*nx -= p->dir_x * MOVE_SPEED;
		*ny -= p->dir_y * MOVE_SPEED;
	}
	else if (keycode == 2)
	{
		*nx += p->dir_y * MOVE_SPEED;
		*ny -= p->dir_x * MOVE_SPEED;
	}
}

int	basic_movement(int keycode, t_player *player, t_data *m)
{
	double	new_x;
	double	new_y;

	calculate_new_position(keycode, player, &new_x, &new_y);
	check_collision(m, new_x, new_y);
	return (0);
}

int	exit_window(t_data *m)
{
	mlx_clear_window(m->window->mlx, m->window->window);
	mlx_destroy_window(m->window->mlx, m->window->window);
	free_and_exit(m, 0);
	return (0);
}

void	change_plane(t_player *player, double angle)
{
	double	old_plane_x;

	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}
