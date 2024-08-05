/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:01:52 by naadam            #+#    #+#             */
/*   Updated: 2024/08/05 20:35:08 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	allocate_map(t_map *map, t_data *main)
{
	unsigned int i;
	
	i = 0;
	map->layout = malloc(sizeof(char *) * map->height);
	if (!map->layout)
	{
		main->type = 0;
		error_message(main->type, main);
	}
	while (i < map->height)
	{
		map->layout[i] = malloc(sizeof(char) * map->width);
		if (!map->layout[i])
		{
			main->type = 0;
			error_message(main->type, main);
		}
		i++;
	}
}

void	get_w_h(t_map *map, int fd, t_data *main)
{
	char 	buffer[BUFFER_SIZE];
    size_t 	bytes_read;
	unsigned int		i;

	bytes_read = 1;
	while (bytes_read > 0)
    {
		i = 0;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == (size_t)(-1))
		{
			close(fd);
			main->type = 2;
			error_message(main->type, main);
		}
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				map->height += 1;
			else if (map->height == 0 && buffer[i] != ' ' && buffer[i] != '\t')
				map->width += 1;
			i++;
		}
	}
	close(fd);
}

void	fill_layout(char *file_path, t_map *map, t_data *main)
{
	int fd;
	fd = open(file_path, O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, 0, 0) < 0)
	{
		main->type = 2;
		error_message(main->type, main);
	}
	get_w_h(map, fd, main);
	allocate_map(map, main); //Allocate memory for map
	maptolayout(file_path, map, main, fd);// Find player position and fill map
	unsigned int y = -1;
	unsigned int x = -1;
	while (++y < map->height)
	{
		while (++x < map->width)
			printf("%d\n", map->layout[y][x]);
	}
	//Draw the map and the player
}

void    parse_map(t_data *main)
{
	main->map = malloc(sizeof(t_map) * 1);
	if (!main->map)
	{
		main->type = 0;
		error_message(main->type, main);
	}
	init_map(main->map);
	fill_layout(main->parse->file_path, main->map, main);
}