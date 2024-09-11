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

void	check_collision(t_data *m, double new_x, double new_y)
{
	int			t;
	t_player	*pl;
	int			map_x;
	int			map_y;

	pl = m->player;
	t = m->parse->tile_size;
	map_x = (int)(new_x / t);
	map_y = (int)(new_y / t);
	if (m->map->layout[map_y][map_x] != '1')
	{
		pl->pos_x = new_x;
		pl->pos_y = new_y;
	}
}