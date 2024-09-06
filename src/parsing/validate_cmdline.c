/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:12:10 by naadam            #+#    #+#             */
/*   Updated: 2024/09/06 15:55:08 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

bool isEmptyString(char *str)
{
    if (str == NULL)
		return true;
    while (*str)
	{
		if (!is_space(*str))
			return false;
        str++;
    }
    return true;
}

bool check_dir(char *arg)
{
	int fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

bool	check_cub(t_parse *p)
{
	int len;
	int fd;
	
	len = ft_strlen(p->file_path);
	if (len < 4)
		return (false);
	if (p->file_path[len - 1] == 'b' && p->file_path[len - 2] == 'u' && p->file_path[len - 3] == 'c'
		&& p->file_path[len - 4] == '.')
	{
		fd = open(p->file_path, O_RDONLY);
		if (fd < 0)
			return (false);
		close(fd);
		return (true);
	}
	return (false);
}

void	check_input(char **av, t_data *m)
{
	m->parse->file_path = ft_strdup(av[1]);
	if (check_dir(m->parse->file_path) == true)
		error_message(1, m);
	if (check_cub(m->parse) == false)
		error_message(2, m);
} 

void	validate_cmdline(char **av,  t_data *m)
{
	m->parse = malloc(sizeof(t_parse));
	if (!m->parse)
		error_message(0, m);
	init_parse(m->parse);
	check_input(av, m);
	parse_map(m);
}