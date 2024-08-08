/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:39:54 by naadam            #+#    #+#             */
/*   Updated: 2024/08/08 12:06:19 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_map(t_map *map)
{
	map->layout = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
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
	t->buffer = NULL;
}

void	init_main(t_data *m)
{
	m->parse = NULL;
	m->map = NULL;
	m->window = NULL; 
}