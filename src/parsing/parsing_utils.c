/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:39:54 by naadam            #+#    #+#             */
/*   Updated: 2024/08/04 20:03:20 by naadam           ###   ########.fr       */
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
    map->row_length = 0;
    map->column = 0;
}