/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:27 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 19:56:58 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_texture(t_texture *t)
{
	if (t)
	{
		if (t->no)
			free(t->no);
		if (t->so)
			free(t->so);
		if (t->ea)
			free(t->ea);
		if (t->we)
			free(t->we);
	}
}

void	free_color(t_color *c)
{
	if (c)
	{
		if (c->r)
			free(c->r);
		if (c->g)
			free(c->g);
		if (c->b)
			free(c->b);
	}
}

void	free_point(t_point *p)
{
	t_point	*tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp->row);
		tmp->row = NULL;
		free(tmp);
	}
}

void	free_par(t_parse *parse)
{
	if (parse)
	{
		if (parse->file_path)
			free(parse->file_path);
		if (parse->buf)
			free(parse->buf);
		if (parse->array)
			free_array(parse->array);
		if (parse->texture)
			free_texture(parse->texture);
		if (parse->color)
			free_color(parse->color);
		if (parse->point)
			free_point(parse->point);
		free(parse);
	}
}
