/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptostruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:46:35 by naadam            #+#    #+#             */
/*   Updated: 2024/08/07 17:10:22 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	read_file(int fd, t_parse *p, t_data *m)
{
	size_t rd_bytes;

	rd_bytes = 1;
	p->buf = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!p->buf)
	{
		m->type = 0;
		error_message(m->type, m);
	}
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, p->buf, BUFFER_SIZE);
		if (rd_bytes == (size_t)(-1))
		{
			m->type = 2;
			error_message(m->type, m);
		}
	}
}

void	save_xpm(char *s, t_texture *t)
{
	int i;
	int m;
	char *b;

	i = -1;
	m = 0;
	while (s[++i])
	{
		if (s[i + 1] == '.')
		{
			while (s[++i])
				m += 1;
		}
		// if (m > 0)
	}
	if (ft_strncmp("./src/textures", &s[i], 15) == 0)	
}

void	checkstrtexture(char *s, t_texture *t)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i + 1] && s[i] == 'N' && s[i + 1] == 'O')
			save_xpm(&s[i], t);
	}
}

void	parse_texture(t_data *m, t_parse *p)
{
	(void) m;
	int 		i;
	char **array;

	i = -1;
	p->texture = malloc(sizeof(t_texture) * 1);
	array = ft_split(p->buf, '\n');
	while (array[++i])
	{
		checkstrtexture(array[i], p->texture);
	}
}

void	maptostruct(t_data *m, t_parse *p)
{
	parse_texture(m, p);
}

void	parse_map(t_data *m)
{
	int fd;

	fd = open(m->parse->file_path, O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX 
		|| read(fd, 0, 0) < 0)
	{
		m->type = 2;
		error_message(m->type, m);
	}
	read_file(fd, m->parse, m);
	close(fd);
	maptostruct(m, m->parse);
}