/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:25 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 21:21:22 by naadam           ###   ########.fr       */
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
	redraw(m);
}

int	calculatetilesize(int window_dimension, int map_dimension)
{
	int	o;

	o = window_dimension / map_dimension - 1;
	return (o);
}

void	set_tilesize(t_parse *parse) //Set the size of the tiles
{
	int	k;
	int	j;

	k = calculatetilesize(M_WIDTH, parse->max);
	j = calculatetilesize(M_HEIGHT, parse->rows);
	if (k < j)
		parse->tile_size = k;
	else
		parse->tile_size = j;
}

void	draw_grid(t_data *m)
{
	set_win_values(m->window, m);
	set_tilesize(m->parse);
	draw(m, m->map, m->cur, m->parse);
}

void	draw(t_data *m, t_map *map, t_cur *cur, t_parse *p)
{
	char	**t;

	cur->y = 0;
	t = map->layout;
	while (cur->y < p->rows)
	{
		cur->x = 0;
		while (cur->x <= p->max)
		{
			if (t[cur->y][cur->x] == '1')
				draw_square(m, cur, p, 0x0000FF);
			else if (t[cur->y][cur->x] == '0')
				draw_square(m, cur, p, 0x000000);
			else if (t[cur->y][cur->x] == 'N' || t[cur->y][cur->x] == 'S'
				|| t[cur->y][cur->x] == 'E' || t[cur->y][cur->x] == 'W')
			{
				draw_square(m, cur, p, 0x000000);
				mark_player(m, cur->x, cur->y, p);
			}
			cur->x++;
		}
		cur->y++;
	}
}
