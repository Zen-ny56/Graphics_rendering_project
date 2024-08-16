/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:41 by naadam            #+#    #+#             */
/*   Updated: 2024/08/16 19:06:13 by naadam           ###   ########.fr       */
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
	int i;

	i = 0;
	if (strncmp(&s[i], "NO", 2) == 0 || strncmp(&s[i], "SO", 2) == 0 ||
		strncmp(&s[i], "WE", 2) == 0 || strncmp(&s[i], "EA", 2) == 0 ||
		strncmp(&s[i], "F", 1) == 0 || strncmp(&s[i], "C", 1) == 0)
		return (0);
	return (1);
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

void	lastcheckpoint(char *s, t_data *m)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'N' && s[i] != 'S' && s[i] != 'W' && s[i] != 'E')
			error_message(7, m);
	}
}

char	*processtring(char *s, t_parse *p, int rows)
{
	int	i;
	char *b;
	int		j;

	i = -1;
	j = 0;
	b = malloc(sizeof(char) * p->max + 1);
	while (s[++i])
	{
		if (rows == 0 || (rows  == p->rows - 1))
		{
			if (s[i] == ' ')
				b[j++] = '1'; 
		}
		if (s[i] == ' ' && i == 0 && rows != 0)
			b[j++] = '1';
		if (s[i] == ' ' && i > 0)
			b[j++] = '0';
		if (s[i] == '1' || s[i] == '0' || s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
			b[j++] = s[i];
	}
	while (j < p->max)
	{
		if (rows == 0 || (rows == p->rows - 1))
			b[j++] = '1';
		else
			b[j++] = '0';
	}
	b[j] = '1';
	b[j + 1] = '\0';
	return (b);
}

void	fill_point(char *s, t_data *m, int rows, t_point **head)
{
	t_point		*new;
  
	m->parse->encountered = 1;
	new = (t_point *)malloc(sizeof(t_point));
	new->x_length = m->parse->max;
	new->row = processtring(s, m->parse, rows);
	new->next = NULL;
	lastcheckpoint(new->row, m);
	add_point_to_list(head, new);
}

void    parse_point(t_data *m, t_parse *p)
{
	int i;
	int	rows;

	i = -1;
	rows = 0;
	p->point = NULL;
	find_max(p);
	count_rows(p);
	while (p->array[++i])
	{
		if (!islineempty(p->array[i]) || !precheckinterference(p->array[i]))
		{
			if (p->encountered == 1)
				error_message(9, m);
			continue;
		}
		fill_point(p->array[i], m, rows, &(p->point));
		rows++;
	}
	printf("%d\n", p->rows);
}
