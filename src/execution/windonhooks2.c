/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windonhooks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:22:22 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 22:22:33 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	change_direction(t_player *player, double angle)
{
	double	old_dir_x;

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
