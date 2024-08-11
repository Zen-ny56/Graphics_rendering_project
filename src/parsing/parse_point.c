/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:41 by naadam            #+#    #+#             */
/*   Updated: 2024/08/11 16:26:22 by naadam           ###   ########.fr       */
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
	int i = 0;
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
	{
		*head = new_point;
	}
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
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '0' && s[i] != '1'
			&& s[i] != 'N' && s[i] != 'S' && s[i] != 'W' && s[i] != 'E')
			error_message(7, m);
	}	
}

char	*processtring(char *s)
{
	int		i;
	int		len;
	char	*b;
	int		j;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			continue ;
		len++;
	}
	b = malloc(sizeof(char) * len + 1);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			continue;
		b[j] = s[i];
		j++;
	}
	b[j] = '\0';
	return (b);
}

void	fill_point(char *s, t_data *m, t_point **head)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->row = processtring(s);
	new->x_length = ft_strlen(new->row);
	new->next = NULL;
	lastcheckpoint(new->row, m);
	add_point_to_list(head, new);
}

void    parse_point(t_data *m, t_parse *p)
{
	int i;

	i = -1;
	p->point = NULL;
	while (p->array[++i])
	{
		if (!islineempty(p->array[i]) || !precheckinterference(p->array[i]))
			continue;
		fill_point(p->array[i], m, &(p->point));
	}
}
