/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmappin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:46:13 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 21:18:18 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	tex_onwhich_side(t_data *data)
{
	if (data->player->side == 0 && data->player->raydir_x > 0)
	{
		data->window->tex_w = data->window->tex_w1;
		data->window->tex_h = data->window->tex_h1;
	}
	else if (data->player->side == 0 && data->player->raydir_x < 0)
	{
		data->window->tex_w = data->window->tex_w2;
		data->window->tex_h = data->window->tex_h2;
	}
	else if (data->player->side == 1 && data->player->raydir_y > 0)
	{
		data->window->tex_w = data->window->tex_w3;
		data->window->tex_h = data->window->tex_h3;
	}
	else if (data->player->side == 1 && data->player->raydir_y < 0)
	{
		data->window->tex_w = data->window->tex_w4;
		data->window->tex_h = data->window->tex_h4;
	}
}

void	texture_prep(t_data *data)
{
	if (data->player->side == 0)
		data->wall->wallx = data->player->pos_y + data->player->perpwalldist
			* data->player->raydir_y;
	else
		data->wall->wallx = data->player->pos_x + data->player->perpwalldist
			* data->player->raydir_x;
	data->wall->wallx -= floor(data->wall->wallx);
	tex_onwhich_side(data);
	data->window->texxx = (int)(data->wall->wallx
			* (double)(data->window->tex_w));
	if (data->player->side == 0 && data->player->raydir_x > 0)
		data->window->texxx = data->window->tex_w - data->window->texxx - 1;
	if (data->player->side == 1 && data->player->raydir_y < 0)
		data->window->texxx = data->window->tex_w - data->window->texxx - 1;
}

int	get_color(t_data *data, int tex_y)
{
	int	color;
	int	tex_x;
	int	tex_w;
	int	*texture_data;

	tex_x = data->window->texxx;
	tex_w = data->window->tex_w;
	if (data->player->side == 0)
	{
		if (data->player->raydir_x > 0)
			texture_data = data->window->cnv_addr1;
		else
			texture_data = data->window->cnv_addr2;
	}
	else
	{
		if (data->player->raydir_y > 0)
			texture_data = data->window->cnv_addr3;
		else
			texture_data = data->window->cnv_addr4;
	}
	tex_y = tex_y % data->window->tex_h;
	tex_x = tex_x % data->window->tex_w;
	color = texture_data[tex_y * tex_w + tex_x];
	return (color);
}
