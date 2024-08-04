/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:01:52 by naadam            #+#    #+#             */
/*   Updated: 2024/08/04 21:02:40 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	allocate_map(t_map *map, t_data *main)
{
	int i;
	
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

void	get_w_h(char *file_path, t_map *map, int fd, t_data *main)
{
	char 	buffer[BUFFER_SIZE];
    size_t 	bytes_read;
	int		i;

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
	get_w_h(file_path, map, fd, main);
	allocate_map(map, main);
	//Read from fd again and fill values
	//Draw the map and the player
}

void    parse_map(t_data *main, t_map *map)
{
	main->map = malloc(sizeof(t_data) * 1);
	if (!main->map)
	{
		main->type = 0;
		error_message(main->type, main);
	}
	initialmapvalues(map);
	fill_layout(main->parse->file_path, map, main);
}