/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:27 by naadam            #+#    #+#             */
/*   Updated: 2024/09/12 01:10:39 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_textures_add(t_window *w)
{
	if (w->cnv_img1)
		w->cnv_addr1 = (int *)mlx_get_data_addr(w->cnv_img1, &w->cnv_bpp1,
				&w->cnv_ll1, &w->cnv_en1);
	if (w->cnv_img2)
		w->cnv_addr2 = (int *)mlx_get_data_addr(w->cnv_img2, &w->cnv_bpp2,
				&w->cnv_ll2, &w->cnv_en2);
	if (w->cnv_img3)
		w->cnv_addr3 = (int *)mlx_get_data_addr(w->cnv_img3, &w->cnv_bpp3,
				&w->cnv_ll3, &w->cnv_en3);
	if (w->cnv_img4)
		w->cnv_addr4 = (int *)mlx_get_data_addr(w->cnv_img4, &w->cnv_bpp4,
				&w->cnv_ll4, &w->cnv_en4);
}

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
