/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:41 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 13:23:21 by naadam           ###   ########.fr       */
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

char *processtring(char *s, t_parse *p, int rows, t_data *m)
{
    int i = -1;
    int j = 0;
    char *b;

    // Allocate memory for the processed line, with one extra space for the null terminator
    b = malloc(sizeof(char) * (p->max + 2)); 
    if (!b)
        error_message(12, m); // Handle allocation error if necessary

    // Process each character in the input string
    while (s[++i])
    {
        // Convert spaces at the borders (first or last row) to walls ('1')
        if (rows == 0 || rows == p->rows - 1)
        {
            if (s[i] == ' ')
                b[j++] = '1';
            else
                b[j++] = s[i];
        }
        else
        {
            // Convert the first space of each line to '1' (if it's a wall)
            if (s[i] == ' ' && i == 0)
                b[j++] = '1';
            else if (s[i] == ' ') // Convert any other space within the line to '0'
                b[j++] = '0';
            else // Keep any valid map characters unchanged
                b[j++] = s[i];
        }
    }

    // Fill remaining spaces up to p->max
    while (j < p->max)
    {
        if (rows == 0 || rows == p->rows - 1)
            b[j++] = '1';  // Fill with '1' if it's the first or last row
        else
            b[j++] = '0';  // Fill with '0' for internal spaces
    }
    // Ensure the last character is a wall for consistency
    b[j] = '1';
    b[j + 1] = '\0';

    // Debug print to show the processed line
    return (b);
}

void	fill_point(char *s, t_data *m, int rows, t_point **head)
{
	t_point		*new;
  
	m->parse->encountered = 1;
	new = (t_point *)malloc(sizeof(t_point));
	new->x_length = m->parse->max;
	new->row = processtring(s, m->parse, rows, m);
	// printf("%s\n",new->row);
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
	// t_point *temp = p->point;
	// while (temp)
	// {
	// 	printf("%s\n", temp->row);
	// 	temp = temp->next;
	// }
	// printf("%d\n", p->rows);
}
