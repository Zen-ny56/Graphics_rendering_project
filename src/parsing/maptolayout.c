/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptolayout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:11:39 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 20:02:00 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	allowidtheight(int y, t_map *map, t_point **po, t_data *m)
{
	int		x;
	t_point	*temp;

	x = 0;
	temp = *po;
	while (x < y)
	{
		map->layout[x] = malloc(sizeof(char) * temp->x_length + 1);
		if (!map->layout[x])
			error_message(0, m);
		x++;
		temp = temp->next;
	}
}

void	allocateheight(int y, t_map *map, t_data *m)
{
	int	i;

	i = 0;
	map->layout = malloc(sizeof(char *) * (y + 1));
	if (!map->layout)
		error_message(0, m);
	while (i < y)
	{
		map->layout[i] = NULL;
		i++;
	}
	map->layout[y] = NULL;
}

void	fill_layout(int y, t_map *map, t_point **head, t_data *m)
{
	int		max;
	t_point	*temp;

	(void)m;
	max = y;
	temp = *head;
	y = 0;
	while (y < max)
	{
		strcpy(map->layout[y], temp->row);
		y++;
		temp = temp->next;
	}
}

void	pointolayout(t_data *m, t_parse *p, t_point *po)
{
	int		y;
	int		i;
	char	**copy;

	y = point_len(po);
	m->map = malloc(sizeof(t_map));
	init_map(m->map);
	allocateheight(y, m->map, m);
	allowidtheight(y, m->map, &(p->point), m);
	fill_layout(y, m->map, &(p->point), m);
	i = -1;
	while (m->map->layout[++i])
		printf("%s\n", m->map->layout[i]);
	setplayerposition(y, m->map, m);
	add_coordinatestruct(m->map->layout, m, y);
	copy = deep_copy_layout(m->map->layout, y);
	checkboundaries(m, m->cur, m->map);
	free_altered(m->map);
	m->map->layout = copy;
}
