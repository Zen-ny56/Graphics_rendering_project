/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:01:52 by naadam            #+#    #+#             */
/*   Updated: 2024/08/16 16:07:03 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

