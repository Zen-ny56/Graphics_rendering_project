/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:01:52 by naadam            #+#    #+#             */
/*   Updated: 2024/08/17 21:11:19 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill(char **tab, t_cur *size, t_cur *cur, int *enclosed)
{
	printf("{%c} \n", tab[cur->y][cur->x]);
	if (cur->y <= 0 || cur->y >= size->y || cur->x <= 0 || cur->x >= size->x)
	{
		if (tab[cur->y][cur->x] == '0')
		{
			*enclosed = 0;
		}
		return ;
	}
	if (tab[cur->y][cur->x] == '1' || tab[cur->y][cur->x] == 'F')
		return;
	tab[cur->y][cur->x] = 'F';
	fill(tab, size, &(t_cur){cur->x - 1, cur->y}, enclosed);
	fill(tab, size, &(t_cur){cur->x + 1, cur->y}, enclosed);
	fill(tab, size, &(t_cur){cur->x, cur->y - 1}, enclosed);
	fill(tab, size, &(t_cur){cur->x, cur->y + 1}, enclosed);
}

void	checkboundaries(t_data *m, t_cur *cur, t_map *map)
{
	(void)cur;
	t_cur	begin;
	t_cur	size;
	int		enclosed;

	enclosed = 1;
	begin.x = map->px;
	begin.y = map->py;
	size.x = m->parse->max;
	size.y = m->parse->rows;
	// printf("Players starting coordinate x{%d}y{%d} and boundaries x{%d} y{%d}\n", begin.x, begin.y, size.x, size.y);
	if (begin.x <= 0 || begin.y >= size.y || begin.x >= size.x || begin.y <= 0)
		error_message(10, m);
	fill(map->layout, &size, &begin, &enclosed);
	if (enclosed != 1)
		error_message(10, m);
}

void	add_coordinatestruct(char **layout, t_data *m, int y)
{
	int	i;
	int	j;

	m->cur = malloc(sizeof(t_cur));
	i = 0;
	while (i < y)
	{
		m->cur->y = i;
		j = 0;
		while (layout[i][j])
		{
			m->cur->x = j;
			j++;
		}
		i++;
	}
}

void    setplayerposition(int y, t_map *map, t_data *m)
{
	int i;
	int	x;

	i = 0;
	while (i < y)
	{
		x = 0;
		while (map->layout[i][x])
		{
			if (map->layout[i][x] == 'N' || map->layout[i][x] == 'S' ||
				map->layout[i][x] == 'W' || map->layout[i][x] == 'E')
			{
				if (map->px != -1 || map->py != -1)
					error_message(8, m);
				map->py = i;
				map->px = x;
			}
			x++;
		}
		i++;
	}
}

