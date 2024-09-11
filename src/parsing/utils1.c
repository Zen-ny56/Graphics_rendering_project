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

bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

bool	isemptystring(char *str)
{
	if (str == NULL)
		return (true);
	while (*str)
	{
		if (!is_space(*str))
			return (false);
		str++;
	}
	return (true);
}

void	free_altered(t_map *map)
{
	int	i;

	i = 0;
	while (map->layout[i])
	{
		free(map->layout[i]);
		map->layout[i++] = NULL;
	}
	map->layout = NULL;
}

char	**deep_copy_layout(char **layout, int y)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * y + 1);
	if (!copy)
		return (NULL);
	while (i < y)
	{
		copy[i] = ft_strdup(layout[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	point_len(t_point *po)
{
	t_point	*temp;
	int		i;

	temp = po;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
