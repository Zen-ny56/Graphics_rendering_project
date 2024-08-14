/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptostruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:46:35 by naadam            #+#    #+#             */
/*   Updated: 2024/08/14 18:38:01 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	read_file(int fd, t_parse *p, t_data *m)
{
	size_t rd_bytes;

	rd_bytes = 1;
	p->buf = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!p->buf)
		error_message(0, m);
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, p->buf, BUFFER_SIZE);
		if (rd_bytes == (size_t)(-1))
			error_message(2, m);
	}
	p->buf[ft_strlen(p->buf)] = '\0';
}

void	maptostruct(t_data *m, t_parse *p)
{
	parse_texture(m, p);
	parse_color(m, p);
	parse_point(m, p);
}

void	parse_map(t_data *m)
{
	int fd;

	fd = open(m->parse->file_path, O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX 
		|| read(fd, 0, 0) < 0)
		error_message(2, m);
	read_file(fd, m->parse, m);
	close(fd);
	maptostruct(m, m->parse);
	pointolayout(m, m->parse, m->parse->point);
}