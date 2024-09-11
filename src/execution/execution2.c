/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:47:19 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 21:01:13 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cal_delta(t_player *player)
{
	if (player->raydir_x == 0)
		player->deltadistx = 1e30;
	else
		player->deltadistx = fabs(1 / player->raydir_x);
	if (player->raydir_y == 0)
		player->deltadisty = 1e30;
	else
		player->deltadisty = fabs(1 / player->raydir_y);
}

void	calwalldist(t_player *player, t_data *m)
{
	if (player->side == 0)
		player->perpwalldist = (player->sidedistx - player->deltadistx);
	else
		player->perpwalldist = (player->sidedisty - player->deltadisty);
	player->perpwalldist /= m->parse->tile_size;
	m->wall->line_height = (int)(M_HEIGHT / (player->perpwalldist));
	m->wall->draw_start = (-m->wall->line_height) / 2 + M_HEIGHT / 2;
	if (m->wall->draw_start < 0)
		m->wall->draw_start = 0;
	m->wall->draw_end = m->wall->line_height / 2 + M_HEIGHT / 2;
	if (m->wall->draw_end >= M_HEIGHT)
		m->wall->draw_end = M_HEIGHT - 1;
}

int	draw_texture(t_data *m, int x, int y)
{
	double	step;
	double	texpos;
	int		tex_y;
	int		color;

	step = 1.0 * m->window->tex_h / m->wall->line_height;
	texpos = (m->wall->draw_start - M_HEIGHT / 2 + m->wall->line_height / 2);
	texpos *= step;
	while (y < m->wall->draw_end)
	{
		tex_y = (int)texpos % m->window->tex_h;
		texpos += step;
		color = get_color(m, tex_y);
		if (m->player->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		my_mlx_pixel_put(m->window, x, y, color);
		y++;
	}
	return (y);
}

void	draw_3d(t_data *m, int x)
{
	int	y;

	y = 0;
	while (y < m->wall->draw_start)
	{
		my_mlx_pixel_put(m->window, x, y, m->parse->color->ceiling_color);
		y++;
	}
	texture_prep(m);
	y = draw_texture(m, x, y);
	while (y < M_HEIGHT)
	{
		my_mlx_pixel_put(m->window, x, y, m->parse->color->floor_color);
		y++;
	}
}

void	set_raydir(t_player *player, t_window *window, t_data *m)
{
	int	x;

	x = 0;
	add_textures(m, m->window, m->parse);
	while (x < M_WIDTH)
	{
		(void)window;
		player->camerax = (2 * x / (double)M_WIDTH - 1);
		player->raydir_x = player->dir_x + player->plane_x * player->camerax;
		player->raydir_y = player->dir_y + player->plane_y * player->camerax;
		cal_side(player, m->map);
		cal_delta(player);
		performdda(player, m->map, m->parse);
		calwalldist(player, m);
		draw_3d(m, x);
		x++;
	}
}
