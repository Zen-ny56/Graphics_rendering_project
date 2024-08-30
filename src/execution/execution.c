/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:03 by naadam            #+#    #+#             */
/*   Updated: 2024/08/30 20:47:33 by naadam           ###   ########.fr       */
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

void	cal_side(t_player *player, t_map *map, t_parse *p)
{
	map->mapX = (int)player->pos_x / p->tile_size;
	map->mapY = (int)player->pos_y / p->tile_size;
	if (player->raydir_x < 0)
	{
    	player->stepX = -1; //Stepping to the left side
		player->sideDistX = (player->pos_x - map->mapX) * player->deltaDistX; // Distance to a left border of a grid
	}
	else
	{
		player->stepX = 1; // Stepping to the right side
		player->sideDistX = (map->mapX + 1.0 - player->pos_x) * player->deltaDistX; // Distance to a right border of a grid
	}
	if (player->raydir_y < 0)
	{
		player->stepY = -1; // Stepping down
		player->deltaDistY = (player->pos_y - map->mapY) * player->deltaDistY; // Distance to the border below
	}
	else
	{
		player->stepY = 1; // Stepping up
		player->deltaDistY = (map->mapY + 1.0 - player->pos_y) * player->deltaDistY; // Distance to the upperside
	}
}

void	performDDA(t_player *player, t_map *map)
{
	int	hit;
	int	side;

	hit	= 0;
	while (hit == 0)
	{
		if (player->sideDistX < player->sideDistY) //If x is less than y we move vertically
		{
			player->sideDistX += player->deltaDistX; // We add onto the side distance using deltaDistX
			map->mapX += player->stepX; // We step in a vertical direction
			side = 0;
		}
		else
		{
			player->sideDistY += player->deltaDistY; // We move horizontally
			map->mapY += player->stepY; // We step in a horizontal direction
			side = 1;
		}
		if (map->layout[(int)map->mapY][(int)map->mapX] == '1') // Check if the ray hits a 1
			hit = 1; // Assume walls are represented by '1'
	}
}

void	cal_delta(t_player *player)
{
	player->deltaDistX = fabs(1 / player->raydir_x); // Difference between two vertical intersections
	player->deltaDistY = fabs(1 / player->raydir_y); // Difference between two horizontal intersections
}

void draw_line(t_window *w, int x0, int y0, int x1, int y1, int color) // Messed up don't bother reading
{
    // Calculate differences and determine the direction of the line
    int dx = abs(x1 - x0);   // Difference in x
    int dy = abs(y1 - y0);   // Difference in y
    int sx = (x0 < x1) ? 1 : -1; // Step in x direction
    int sy = (y0 < y1) ? 1 : -1; // Step in y direction
    int err = dx - dy; // Error term

    while (1)
    {
        // Draw the current pixel
        my_mlx_pixel_put(w, x0, y0, color); // Replace with your pixel drawing function

        // Check if the line has reached the endpoint
        if (x0 == x1 && y0 == y1) 
            break;

        // Calculate error to determine the next point
        int e2 = 2 * err;

        // Adjust error and step in x direction
        if (e2 > -dy) 
        {
            err -= dy;
            x0 += sx;
        }

        // Adjust error and step in y direction
        if (e2 < dx) 
        {
            err += dx;
            y0 += sy;
        }
    }
}

void	set_raydir(t_player *player, t_window *window, t_data *m)
{
	int	x;

	x = 0;
	while (x < M_WIDTH)
	{
		player->cameraX = (2 * x / (double)M_WIDTH) - 1; // Calculate cameraX for each column
		player->raydir_x = player->dir_x + player->plane_x * player->cameraX; // Calculation of raydir_x
		player->raydir_y = player->dir_y + player->plane_y * player->cameraX; // Calculation of raydir_y
		// Raycasting to take place here
		cal_side(player, m->map, m->parse);
		cal_delta(player);
		performDDA(player, m->map);
		draw_line(window, player->pos_x, player->pos_y, (m->map->mapX * m->parse->tile_size), (m->map->mapY * m->parse->tile_size), 0xFF0000); //This is fucked don't even bother look at what happened here 
		x++;
	}
}

// void	set_raydir(t_player *player, t_window *window)
// {
// 	int	x;
// 	int	i;
// 	double ray_length;
// 	int ray_max_length = 3000; // Define max length for the rays (you can adjust this)

// 	x = 0;
// 	while (x < M_WIDTH)
// 	{
// 		// Calculate the camera's x-coordinate in the camera space
// 		player->cameraX = (2 * x / (double)M_WIDTH) - 1;
		
// 		// Calculate ray direction for the current column
// 		player->raydir_x = player->dir_x + player->plane_x * player->cameraX;
// 		player->raydir_y = player->dir_y + player->plane_y * player->cameraX;

// 		// Draw rays from the player's position
// 		i = 0;
// 		while (i < ray_max_length) // Draw ray up to maximum length
// 		{
// 			ray_length = i * 0.1; // Adjust step size for ray precision

// 			// Calculate the position of the ray
// 			int ray_x = (int)(player->pos_x + ray_length * player->raydir_x);
// 			int ray_y = (int)(player->pos_y + ray_length * player->raydir_y);

// 			// Draw the pixel for the ray
// 			my_mlx_pixel_put(window, ray_x, ray_y, 0xFF0000); // Draw in red color
			
// 			i++;
// 		}
// 		x++;
// 	}
// }

void	raycasting(t_data *main)
{
	set_direction(main->player); // Player direction is being set
	set_plane(main->player); // Set where the player is looking
	set_raydir(main->player, main->window, main); 
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