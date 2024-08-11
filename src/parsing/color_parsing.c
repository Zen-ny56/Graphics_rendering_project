/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:36:49 by naadam            #+#    #+#             */
/*   Updated: 2024/08/11 13:10:50 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	lastcheckcolor(t_color *c, t_data *m)
{
	if (c->b[0] < 0 || c->b[1] < 0 || c->g[0] < 0 || c->g[1] < 0
		|| c->r[0] < 0 || c->r[1] < 0)
		error_message(6, m);
	if (!(c->b[0] > -1 && c->b[0] < 256))
		error_message(6, m);
}

void	save_color(char *s, t_color *c, t_data *m)
{
	int len;
	int	k;

	k = 0;
	len = ft_strlen(&s[k]) - 1;
	while (len >= 0)
	{
		if (s[len] == 'F' || s[len] == 'C' || s[len] == ',')
		{
			store_color(&s[len] ,c ,m ,k);
			k++;
		}
		len--;
	}
}

void	checkcolors(char *s, t_color *c, t_data *m)
{
	int i;

	i = 0;
	while (s[i + 1])
	{
		if ((s[i] == 'F') || (s[i] == 'C'))
			save_color(&s[i], c, m);
		i++;
	}
}

void	parse_color(t_data *m, t_parse *p)
{
	p->color = malloc(sizeof(t_color));
	if (!p->color)
		error_message(0, m);
	init_color(p->color);
	int i = -1;
	while (p->array[++i])
		checkcolors(p->array[i], p->color, m);
	lastcheckcolor(p->color, m);
}