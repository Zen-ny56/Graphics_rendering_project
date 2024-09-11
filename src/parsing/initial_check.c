/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:28:47 by naadam            #+#    #+#             */
/*   Updated: 2024/09/12 00:06:39 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_max(t_parse *p)
{
	int	i;
	int	k;

	i = -1;
	while (p->array[++i])
	{
		k = -1;
		if (!islineempty(p->array[i]) || !precheckinterference(p->array[i]))
			continue ;
		while (p->array[i][++k])
		{
			if (p->max == -1 || k > p->max)
				p->max = k;
		}
	}
}

void	count_rows(t_parse *p)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (p->array[++i])
	{
		if (!islineempty(p->array[i]) || !precheckinterference(p->array[i]))
			continue ;
		k++;
	}
	p->rows = k;
}

void	assign_fc(int num, char c, t_color *cs)
{
	if (c == 'b')
	{
		if (cs->b[0] == -1)
			cs->b[0] = num;
		else if (cs->b[1] == -1)
			cs->b[1] = num;
	}
	else if (c == 'g')
	{
		if (cs->g[0] == -1)
			cs->g[0] = num;
		else if (cs->g[1] == -1)
			cs->g[1] = num;
	}
	else if (c == 'r')
	{
		if (cs->r[0] == -1)
			cs->r[0] = num;
		else if (cs->r[1] == -1)
			cs->r[1] = num;
	}
}
