/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmappin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:46:13 by naadam            #+#    #+#             */
/*   Updated: 2024/09/07 18:59:36 by naadam           ###   ########.fr       */
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
	if (data->player->side == 0) // Check where the ray exactly hits the wall
		data->wall->wallX = data->player->pos_y + data->player->perpWallDist * data->player->raydir_y;
	else
		data->wall->wallX = data->player->pos_x + data->player->perpWallDist * data->player->raydir_x;
	data->wall->wallX -= floor(data->wall->wallX); // if wallX is 7.89, remove the fractional part = 0.89
	tex_onwhich_side(data); // Ensure this function is properly defined to set the texture dimensions
	data->window->texX = (int)(data->wall->wallX * (double)(data->window->tex_w)); // Adjusting the texture to avoid mirroring effect
	// Correct the texture x-coordinate for rays hitting the left or bottom sides of objects
	if (data->player->side == 0 && data->player->raydir_x > 0)
		data->window->texX = data->window->tex_w - data->window->texX - 1;
	if (data->player->side == 1 && data->player->raydir_y < 0)
		data->window->texX = data->window->tex_w - data->window->texX - 1;
    // printf("%f\n", data->window->texX);
}

// void	texture_loop(t_data *data, int x)
// {
// 	double	step;
// 	double	texpos;
// 	int		y;
// 	int		color;

// 	color = 0;
// 	texture_prep(data); // Bu fonksiyonun detaylarına da ihtiyacınız olacak
// 	step = 1.0 * data->window->tex_h / data->wall->line_height;
// 	texpos = (data->wall->draw_start - data->window->height / 2 + data->wall->line_height / 2) * step;
// 	y = data->wall->draw_start;
// 	while (y < data->wall->draw_end + 1)
// 	{
// 		int texy = (int)texpos & (data->window->tex_h - 1);
// 		texpos += step;
// 		color = get_color(data); // Bu fonksiyon, doku ve renk bilgilerini alıp işlemelidir.
// 		if (data->player->side == 1)
// 			color = (color >> 1) & 8355711;
// 		data->window->addr[y * data->window->line_len + x] = color; // Burada line_len kullanılması daha uygun
// 		y++;
// 	}
// }

int get_color(t_data *data, int tex_y)
{
    int color;
    int tex_x = data->window->texX; // The x-coordinate in the texture
    int tex_w = data->window->tex_w; // The width of the texture
    int *texture_data;

    if (data->player->side == 0)
    {
        if (data->player->raydir_x > 0)
            texture_data = data->window->cnv_addr1; // East wall
        else
            texture_data = data->window->cnv_addr2; // West wall
    }
    else
    {
        if (data->player->raydir_y > 0)
            texture_data = data->window->cnv_addr3; // North wall
        else
            texture_data = data->window->cnv_addr4; // South wall
    }
    color = texture_data[tex_y * tex_w + tex_x]; // Get the color from the texture
    return color;
}
