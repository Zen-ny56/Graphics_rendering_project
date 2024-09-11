/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:36:49 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 12:50:47 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	combine_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	lastcheckcolor(t_color *c, t_data *m)
{
	if (c->b[0] < 0 || c->b[1] < 0 || c->g[0] < 0 || c->g[1] < 0
		|| c->r[0] < 0 || c->r[1] < 0)
		error_message(6, m);
	if (!(c->b[0] >= 0 && c->b[0] < 256) || !(c->b[1] >= 0 && c->b[1] < 256)
		|| !(c->g[0] >= 0 && c->g[0] < 256) || !(c->g[1] >= 0 && c->g[1] < 256)
		|| !(c->r[0] >= 0 && c->r[0] < 256) || !(c->r[1] >= 0 && c->r[1] < 256))
		error_message(6, m);
	if (c->cflag == 0)
	{
		c->floor_color = combine_rgb(c->r[0], c->g[0], c->b[0]);
		c->ceiling_color = combine_rgb(c->r[1], c->g[1], c->b[1]);
	}
	else
	{
		c->floor_color = combine_rgb(c->r[1], c->g[1], c->b[1]);
		c->ceiling_color = combine_rgb(c->r[0], c->g[0], c->b[0]);
	}
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
		{
			if (s[i] == 'F' && c->cflag < 0)
				c->cflag = 0;
			save_color(&s[i], c, m);
		}
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