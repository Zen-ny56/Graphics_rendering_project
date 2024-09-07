/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:03 by naadam            #+#    #+#             */
/*   Updated: 2024/09/07 20:46:42 by naadam           ###   ########.fr       */
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

void	cal_side(t_player *player, t_map *map)
{
	map->mapX = (int)player->pos_x;
	map->mapY = (int)player->pos_y;
	if (player->raydir_x < 0)
	{
    	player->stepX = -1; //Stepping to the left side
		player->sideDistX = (player->pos_x - map->mapX); // Distance of left border
	}
	else
	{
		player->stepX = 1; // Stepping to the right side
		player->sideDistX = (map->mapX + 1.0 - player->pos_x); // Distance to right border
	}
	if (player->raydir_y < 0)
	{
		player->stepY = -1; // Stepping down
		player->sideDistY = (player->pos_y - map->mapY); // Distance to the border below
	}
	else
	{
		player->stepY = 1; // Stepping up
		player->sideDistY = (map->mapY + 1.0 - player->pos_y); // Distance to upperside
	}
}

void draw_ray(t_window *w, t_player *player, int color)
{
    // Draw the ray in short segments
    double current_x = player->pos_x;
    double current_y = player->pos_y;
    double distance_remaining = player->perpWallDist;
    while (distance_remaining > 0)
    {
        // Convert current position to pixel coordinates
		my_mlx_pixel_put(w, (int)current_x, (int)current_y, color); // Draw that bit of the line
		current_x += player->raydir_x;// Update the current x position
		current_y += player->raydir_y;// Update the current y position
		distance_remaining -= 1;// Decrease the remaining distance
    }
}

void	performDDA(t_player *player, t_map *map, t_parse *p)
{
	int	hit;

	hit	= 0;
	while (hit == 0)
	{
		if (player->sideDistX < player->sideDistY) //If x is less than y we move vertically
		{
			player->sideDistX += player->deltaDistX; // We add onto the side distance using deltaDistX
			map->mapX += player->stepX; // We step in a vertical direction
			player->side = 0; // Since it touches the x-plane we're going to set it to zero
		}
		else
		{
			player->sideDistY += player->deltaDistY; // We move horizontally
			map->mapY += player->stepY; // We step in a horizontal direction
			player->side = 1; // Since it touches the y-plane we're going to set it to one
	 	}
		if (map->layout[map->mapY / p->tile_size][map->mapX / p->tile_size] == '1') // Divide by tile_size if just to align our tiles and pixels
			hit = 1; // Will leave loop since wall has been hit
	}
}

void	cal_delta(t_player *player)
{
	if (player->raydir_x == 0)
		player->deltaDistX = 1e30; // Handles edge case of division by zero
	else
		player->deltaDistX = fabs(1 / player->raydir_x); // Difference between two vertical intersections
	if (player->raydir_y == 0)
		player->deltaDistY = 1e30; // Handle edge case of division by zero
	else
		player->deltaDistY = fabs(1 / player->raydir_y); // Difference between two horizontal intersections
}

void	calWallDist(t_player *player, t_data *m)
{
	if (player->side == 0)
		player->perpWallDist = player->sideDistX - player->deltaDistX;
	else
		player->perpWallDist = player->sideDistY - player->deltaDistY;
	m->wall->line_height = (int)(M_HEIGHT / player->perpWallDist);
	// printf("%d\n", m->wall->line_height);
    m->wall->draw_start = (M_HEIGHT / 2) - (m->wall->line_height / 2);
	// printf("%d %d\n", (m->wall->line_height / 2 + M_HEIGHT / 2 , m->wall->draw_start);
	if (m->wall->draw_start < 0)
		m->wall->draw_start = 0;
	m->wall->draw_end = m->wall->line_height / 2 + M_HEIGHT / 2;
	if (m->wall->draw_end >= M_HEIGHT)
		m->wall->draw_end = M_HEIGHT - 1;
}

void draw_3d(t_data *m, int x)
{
    int y;
    double step;
    double texpos;
    int tex_y;
    int color;

    for (y = 0; y < m->wall->draw_start; y++) 
    {
        my_mlx_pixel_put(m->window, x, y, m->parse->color->ceiling_color); // X and Y being passed in here
    }
    texture_prep(m);
    step = 1.0 * m->window->tex_h / m->wall->line_height;
    texpos = (m->wall->draw_start - M_HEIGHT / 2 + m->wall->line_height / 2) * step;
    y = m->wall->draw_start;
    while (y < m->wall->draw_end)
    {
        tex_y = (int)texpos & (m->window->tex_h - 1);
        texpos += step;
        color = get_color(m, tex_y); // Function to get the color from the texture
        if (m->player->side == 1) // Darken the texture if it's a side wall
            color = (color >> 1) & 0x7F7F7F;
        my_mlx_pixel_put(m->window, x, y, color); // X and Y being passed in here
        y++;
    }
    for (y = m->wall->draw_end; y < M_HEIGHT; y++) 
    {
        my_mlx_pixel_put(m->window, x, y, m->parse->color->floor_color); // X and Y being passed in here
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
		player->cameraX = (2 * x / (double)M_WIDTH - 1); // Calculate cameraX for each column
		player->raydir_x = player->dir_x + player->plane_x * player->cameraX; // Calculation of raydir_x
		player->raydir_y = player->dir_y + player->plane_y * player->cameraX; // Calculation of raydir_y
		cal_side(player, m->map);
		cal_delta(player);
		performDDA(player, m->map, m->parse);
		calWallDist(player, m);
		draw_3d(m, x);
		// textureMappin(player, m);
		// draw_ray(m->window, m->player, 0x00FF00);			
		x++;
	}
}

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
	main->wall = malloc(sizeof(t_wall));
	main->window = malloc(sizeof(t_window));
	main->player = malloc(sizeof(t_player));
	draw_minimap(main);
	mlx_loop(main->window->mlx);
} 