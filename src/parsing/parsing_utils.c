/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:39:54 by naadam            #+#    #+#             */
/*   Updated: 2024/08/05 18:38:26 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_map(t_map *map)
{
    map->layout = malloc(sizeof(char *));
    map->width = 0;
    map->height = 0;
    map->player_x = 0;
    map->player_y = 0;
}