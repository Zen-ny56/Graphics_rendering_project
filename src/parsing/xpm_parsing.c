/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:08:08 by naadam            #+#    #+#             */
/*   Updated: 2024/08/08 11:43:03 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_xpm(char *r, t_data *m)
{
	int len;
	int	fd;

	len = ft_strlen(r);
	if (check_dir(r) == true)
		error_message(1, m);
	if (len < 4)
		error_message(3, m);
	if (r[len - 1] == 'm' && r[len - 2] == 'p' && r[len - 3] == 'x'
		&& r[len - 4] == '.')
	{
		fd = open(r, O_RDONLY);
		if (fd < 0)
			error_message(3, m);
		close(fd);
		return ;
	}
	error_message(3, m);
}

void	assign_xpm(char *buffer, t_texture *t, t_data *m, int i)
{
	if (buffer[i] == 'N' && buffer[i + 1] == 'O')
	{
		if (t->no)
			error_message(3, m);
		t->no = ft_strdup(&buffer[i]);
	}
	else if (buffer[i] == 'S' && buffer[i + 1] == 'O')
	{
		if (t->so)
			error_message(3, m);
		t->so = ft_strdup(&buffer[i]);
	}
	else if (buffer[i] == 'W' && buffer[i + 1] == 'E')
	{
		if (t->we)
			error_message(3, m);
		t->we = ft_strdup(&buffer[i]);
	}
	else if (buffer[i] == 'E' && buffer[i + 1] == 'A')
	{
		if (t->ea)
			error_message(3, m);
		t->ea = ft_strdup(&buffer[i]);
	}
}

void	save_xpm(char *s, t_texture *t, t_data *m)
{
	int len;
	int i;

	i = 0;
	len = 0;
	assign_xpm(&s[i], t, m, 0);
	if (!t->ea && !t->no && !t->we && !t->so)
		error_message(3, m);
	while (s[i])
	{
		if (s[i] == '.')
		{
			check_xpm(&s[i], m);
			return ;
		}
		i++;
	}
	error_message(3, m);
}

void	checkstrtexture(char *s, t_texture *t, t_data *m)
{
	int	i;

	i = 0;
	while (s[i + 1])
	{
		if ((s[i] == 'N' && s[i + 1] == 'O') || (s[i] == 'S' && s[i + 1] == 'O')
			|| (s[i] == 'W' && s[i + 1] == 'E') || (s[i] == 'E' || s[i + 1] == 'A'))
			save_xpm(&s[i], t, m);
		i++;
	}
}

void	parse_texture(t_data *m, t_parse *p)
{
	int 		i;

	i = -1;
	p->texture = malloc(sizeof(t_texture) * 1);
	init_texture(p->texture);
	p->array = ft_split(p->buf, '\n');
	if (!p->array || !p->texture)
		error_message(0, m);
	while (p->array[++i])
		checkstrtexture(p->array[i], p->texture, m);
	// printf("NORTH %s\n SOUTH %s\n WEST %s\n EAST %s\n", p->texture->no, p->texture->so, p->texture->we, p->texture->ea);
	if (!p->texture->no || !p->texture->so || !p->texture->we || !p->texture->ea)
		error_message(4, m);
}