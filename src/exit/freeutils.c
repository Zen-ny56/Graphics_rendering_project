/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:27 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 22:58:55 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->layout)
			free_array(map->layout);
	}
}

void	free_and_exit(t_data *data, int num)
{
	if (data)
	{
		if (data->player)
			free(data->player);
		if (data->map)
			free_map(data->map);
		if (data->parse)
			free_par(data->parse);
		if (data->wall)
			free(data->wall);
		free(data);
		data = NULL;
		if (num >= 0)
		{
			if (num == 1)
				exit(EXIT_FAILURE);
			else if (num == 0)
				exit(EXIT_SUCCESS);
		}
	}
}
