/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:16:42 by naadam            #+#    #+#             */
/*   Updated: 2024/08/10 21:18:51 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	allocolor(t_color *c, int k)
{
	if (k == 0)
	{
		if (c->b)
			return (1);
		c->b = malloc(sizeof(int) * 2);
		c->b[0] = -1;
		c->b[1] = -1;
		return (1);
	}
	else if (k == 1)
	{
		if (c->g)
			return (2);
		c->g = malloc(sizeof(int) * 2);
		c->g[0] = -1;
		c->g[1] = -1;
		return (2);
	}
	else if (k == 2)
	{
		if (c->r)
			return (3);
		c->r = malloc(sizeof(int) * 2);
		c->r[0] = -1;
		c->r[1] = -1;
		return (3);
	}
	return (-1);
}

void	store_color(char *s, t_color *c, t_data *m, int	k)
{
	int	i;
	int	num;

	i = 0;
	i++;
	num = ft_atoi(&s[i]);
	if (num > -1 && num < 256)
	{
		if (allocolor(c, k) == 1)
			assign_fc(num, 'b', c);
		else if (allocolor(c, k) == 2)
			assign_fc(num, 'g', c);
		else if (allocolor(c, k) == 3)
			assign_fc(num, 'r', c);
		else if (allocolor(c, k) == -1)
			error_message(5, m);
		return ;
	}
}
