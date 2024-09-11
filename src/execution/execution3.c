/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:00:53 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 21:03:52 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	raycasting(t_data *main)
{
	set_direction(main->player);
	set_plane(main->player);
	set_raydir(main->player, main->window, main);
}

void	draw_minimap(t_data *m)
{
	draw_grid(m);
	draw_player(m->window, m->player, m->parse->tile_size);
	raycasting(m);
	mlx_put_image_to_window(m->window->mlx, m->window->window,
		m->window->img, 0, 0);
	mlx_hook(m->window->window, 02, 1L << 0, keypress, m);
	mlx_hook(m->window->window, 17, 1L << 0, exit_window, m);
}

void	execution(t_data *main)
{
	main->wall = malloc(sizeof(t_wall));
	main->window = malloc(sizeof(t_window));
	main->player = malloc(sizeof(t_player));
	draw_minimap(main);
	mlx_loop(main->window->mlx);
}
