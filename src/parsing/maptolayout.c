/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptolayout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:11:39 by naadam            #+#    #+#             */
/*   Updated: 2024/08/05 17:42:22 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    filloneszero(char *buffer, t_map *map, int y, int x)
{
	map->layout[y][x] = buffer[x];
	if (buffer[x] == 'N' || buffer[x] == 'W'
		|| buffer[x] == 'S' || buffer[x] == 'E')
	{
		map->player_x = x;
		map->player_y = y;
	}
}

void	maptolayout(char *file_path, t_map *map, t_data *main, int fd)
{
	char 	buffer[BUFFER_SIZE];
	size_t 	bytes_read;
	unsigned int	y;
	unsigned int	x;

	fd = open(file_path, O_RDONLY);
	y = 0;
	bytes_read = 1;
	while (bytes_read > 0 && y < map->height)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		x = -1;
		if (bytes_read == (size_t)(-1))
		{
			close(fd);
			main->type = 2;
			error_message(main->type, main);
		}
		while (++x < map->width)
			filloneszero(buffer ,map, y, x);
		y++;
	}
	close(fd);
}