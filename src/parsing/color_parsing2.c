/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:16:42 by naadam            #+#    #+#             */
/*   Updated: 2024/09/12 00:08:07 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	alloc_blue(t_color *c)
{
	if (!c->b)
	{
		c->b = malloc(sizeof(int) * 2);
		if (c->b)
		{
			c->b[0] = -1;
			c->b[1] = -1;
		}
	}
}

void	alloc_green(t_color *c)
{
	if (!c->g)
	{
		c->g = malloc(sizeof(int) * 2);
		if (c->g)
		{
			c->g[0] = -1;
			c->g[1] = -1;
		}
	}
}

void	alloc_red(t_color *c)
{
	if (!c->r)
	{
		c->r = malloc(sizeof(int) * 2);
		if (c->r)
		{
			c->r[0] = -1;
			c->r[1] = -1;
		}
	}
}

int	allocolor(t_color *c, int k)
{
	if (k == 0)
	{
		alloc_blue(c);
		return (1);
	}
	else if (k == 1)
	{
		alloc_green(c);
		return (2);
	}
	else if (k == 2)
	{
		alloc_red(c);
		return (3);
	}
	return (-1);
}

void	store_color(char *s, t_color *c, t_data *m, int k)
{
	int	i;
	int	num;
	int	result;

	i = 0;
	i++;
	num = ft_atoi(&s[i]);
	if (num > -1 && num < 256)
	{
		result = allocolor(c, k);
		if (result == 1)
			assign_fc(num, 'b', c);
		else if (result == 2)
			assign_fc(num, 'g', c);
		else if (result == 3)
			assign_fc(num, 'r', c);
		else if (result == -1)
			error_message(5, m);
	}
}
