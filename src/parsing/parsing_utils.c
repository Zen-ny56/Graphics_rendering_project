/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:39:54 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 12:40:31 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map(t_map *map)
{
	map->layout = NULL;
	map->py = -1;
	map->px = -1;
}

void	init_parse(t_parse *parse)
{
	parse->array = NULL;
	parse->file_path = NULL;
	parse->max = -1;
	parse->encountered = -1;
	parse->buf = NULL;
	parse->array = NULL;
	parse->texture = NULL;
	parse->color = NULL;
	parse->point = NULL;
}

void	init_texture(t_texture *t)
{
	t->no = NULL;
	t->so = NULL;
	t->we = NULL;
	t->ea = NULL;
}

void	init_color(t_color *c)
{
	c->g = NULL;
	c->r = NULL;
	c->b = NULL;
	c->cflag = -1;
	c->floor_color = -1;
	c->ceiling_color = -1;
}

void	init_main(t_data *m)
{
	m->parse = NULL;
	m->map = NULL;
	m->player = NULL;
	m->wall = NULL;
	m->window = NULL;
}
