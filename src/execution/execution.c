/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:03 by naadam            #+#    #+#             */
/*   Updated: 2024/08/30 18:55:27 by naadam           ###   ########.fr       */
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

// void	set_raydir(t_player *player, t_window window)
// {
// 	int	x;

// 	x = 0;
// 	while (x < M_WIDTH)
// 	{
// 		player->cameraX = (2 * x / (double)M_WIDTH) - 1; // Calculate cameraX for each column
// 		player->raydir_x = player->dir_x + player->plane_x * player->cameraX; // Calculation of raydir_x
// 		player->raydir_y = player->dir_y + player->plane_y * player->cameraX; // Calculation of raydir_y
// 		// Raycasting to take place here
// 		x++;
// 	}
// }

void	set_raydir(t_player *player, t_window *window)
{
	int	x;
	int	i;
	double ray_length;
	int ray_max_length = 1000; // Define max length for the rays (you can adjust this)

	x = 0;
	while (x < M_WIDTH)
	{
		// Calculate the camera's x-coordinate in the camera space
		player->cameraX = (2 * x / (double)M_WIDTH) - 1;
		
		// Calculate ray direction for the current column
		player->raydir_x = player->dir_x + player->plane_x * player->cameraX;
		player->raydir_y = player->dir_y + player->plane_y * player->cameraX;

		// Draw rays from the player's position
		i = 0;
		while (i < ray_max_length) // Draw ray up to maximum length
		{
			ray_length = i * 0.1; // Adjust step size for ray precision

			// Calculate the position of the ray
			int ray_x = (int)(player->pos_x + ray_length * player->raydir_x);
			int ray_y = (int)(player->pos_y + ray_length * player->raydir_y);

			// Draw the pixel for the ray
			my_mlx_pixel_put(window, ray_x, ray_y, 0xFF0000); // Draw in red color
			
			i++;
		}
		x++;
	}
}

void	raycasting(t_data *main)
{
	set_direction(main->player); // Player direction is being set
	set_plane(main->player); // Set where the player is looking
	set_raydir(main->player, main->window); 
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