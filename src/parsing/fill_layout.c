/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:01:52 by naadam            #+#    #+#             */
/*   Updated: 2024/08/14 20:39:36 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	fill(char **tab, t_point )
void	checkboundaries(t_data *m, t_map *map, t_point *point)
{
	fill(map->layout, map->layout[map->playery][map->playerx], );
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
				if (map->playerx != -1 || map->playery != -1)
					error_message(8, m);
				map->playery = i;
				map->playerx = x;
			}
			x++;
		}
		i++;
	}
}

