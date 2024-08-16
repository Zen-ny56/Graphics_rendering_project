/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:28:47 by naadam            #+#    #+#             */
/*   Updated: 2024/08/16 18:36:15 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	checkboundaries(t_data *m, t_parse *p, t_map *map)
// {
// 	flood_fill(map->layout)
// }

void    find_max(t_parse *p)
{
	int	i;
	int	k;

	i = -1;
	while (p->array[++i])
	{
		k = -1;
		while (p->array[i][++k]);
		if (p->max == -1 || k > p->max)
			p->max = k;
	}
}

void	count_rows(t_parse *p)
{
	int i;
	int	k;

	i = -1;
	k = 0;
	while (p->array[++i])
	{
		if (!islineempty(p->array[i]) || !precheckinterference(p->array[i]))
			continue;
		k++;
	}
	p->rows = k;
}