/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:12:10 by naadam            #+#    #+#             */
/*   Updated: 2024/08/05 17:50:05 by naadam           ###   ########.fr       */
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

bool	check_file(t_parse *p)
{
	int len;
	int i;
	int fd;
	
	len = ft_strlen(p->file_path);
	i = 0;
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
	{
		m->type = 1;
		error_message(m->type, m);
	}
	if (check_file(m->parse) == false)
	{
		m->type = 2;
		error_message(m->type, m);
	}
}

void	validate_cmdline(char **av,  t_data *m)
{
	m->parse = malloc(sizeof(t_parse));
	if (!m->parse)
	{
		m->type = MEM_ALLOC;
		error_message(m->type, m);
	}
	check_input(av, m);
}