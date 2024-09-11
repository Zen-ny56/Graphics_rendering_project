/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:12:10 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 23:18:46 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	islineempty(const char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (0);
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	precheckinterference(char *s)
{
	int	i;

	i = 0;
	if (strncmp(&s[i], "NO", 2) == 0 || strncmp(&s[i], "SO", 2) == 0
		|| strncmp(&s[i], "WE", 2) == 0 || strncmp(&s[i], "EA", 2) == 0
		|| strncmp(&s[i], "F", 1) == 0 || strncmp(&s[i], "C", 1) == 0)
		return (0);
	return (1);
}

void	lastcheckpoint(char *s, t_data *m)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'N' && s[i]
			!= 'S' && s[i] != 'W' && s[i] != 'E')
			error_message(7, m);
	}
}

void	add_point_to_list(t_point **head, t_point *new_point)
{
	t_point	*temp;

	if (!*head)
		*head = new_point;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_point;
	}
}

void	fill_point(char *s, t_data *m, int rows, t_point **head)
{
	t_point		*new;

	m->parse->encountered = 1;
	new = (t_point *)malloc(sizeof(t_point));
	new->x_length = m->parse->max;
	new->row = processtring(s, m->parse, rows, m);
	printf("%s\n", new->row);
	new->next = NULL;
	lastcheckpoint(new->row, m);
	add_point_to_list(head, new);
}
