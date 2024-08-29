/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:03 by naadam            #+#    #+#             */
/*   Updated: 2024/08/29 18:30:46 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_plane(t_player *player)
{
	player->plane_length = tan(PI / 6); // Plane length is fixed
	//Set camera plane
	player->plane_x = player->dir_y * player->plane_length; 
	player->plane_y = (player->dir_x * -1) * player->plane_length;
}

void	set_direction(t_player *player)
{
	if (player->angle == 0) // EAST
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (player->angle == PI / 2) // NORTH
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (player->angle == PI) // WEST
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (player->angle == 3 * PI / 2) // SOUTH
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
}

void	set_raydir(t_player *player)
{
	int	x;

	x = 0;
	while (x < M_HEIGHT)
	{
		player->cameraX = (2 * x / (double)M_WIDTH) - 1; // Calculate cameraX for each column
		player->raydir_x = player->dir_x + player->plane_x * player->cameraX; // Calculation of raydir_x
		player->raydir_y = player->dir_y + player->plane_y * player->cameraX; // Calculation of raydir_y
		// Raycasting to take place here
		x++;
	}
}

void	raycasting(t_data *main)
{
	set_direction(main->player); // Player direction is being set
	set_plane(main->player); // Set where the player is looking
	set_raydir(main->player); 
}

void	draw_minimap(t_data *m)
{
	draw_grid(m); //Drawing the grid the player will be on 
	draw_player(m->window, m->player, m->parse->tile_size);//Drawing the player
	raycasting(m);  //Function for drawing the rays
	mlx_put_image_to_window(m->window->mlx, m->window->window, m->window->img, 0, 0);
	mlx_hook(m->window->window, 02, 1L << 0, keypress, m); // Keyboard is handled
	mlx_hook(m->window->window, 17, 1L << 0, exit_window, m); // Close button is handled
}

void    execution(t_data *main)
{
	main->window = malloc(sizeof(t_window));
	main->player = malloc(sizeof(t_player));
	draw_minimap(main);
	mlx_loop(main->window->mlx);
} 