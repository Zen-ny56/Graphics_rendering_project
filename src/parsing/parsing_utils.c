/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:39:54 by naadam            #+#    #+#             */
/*   Updated: 2024/08/11 18:57:05 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_map(t_map *map)
{
	map->layout = NULL;
	map->playerx = -1;
	map->playery = -1;
}

void    init_parse(t_parse *parse)
{
	parse->array = NULL;
	parse->file_path = NULL;
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
	c->argb = NULL;
}

void	init_main(t_data *m)
{
	m->parse = NULL;
	m->map = NULL;
	m->window = NULL; 
}