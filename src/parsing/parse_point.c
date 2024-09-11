/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:41 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 20:11:30 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_middle_row(char *s, int i, char *b, int j)
{
	if (i == 0 || s[i] == ' ')
		b[j++] = '1';
	else if (s[i] == ' ')
		b[j++] = '0';
	else
		b[j++] = s[i];
	return (j);
}

int	handle_first_last_row(char c, char *b, int j)
{
	if (c == ' ')
		b[j++] = '1';
	else
		b[j++] = c;
	return (j);
}

int	fill_remaining_spaces(char *b, int j, t_parse *p, int rows)
{
	while (j < p->max)
	{
		if (rows == 0 || rows == p->rows - 1)
			b[j++] = '1';
		else
			b[j++] = '0';
	}
	return (j);
}

char	*processtring(char *s, t_parse *p, int rows, t_data *m)
{
	int		i;
	int		j;
	char	*b;

	i = -1;
	j = 0;
	b = malloc(sizeof(char) * (p->max + 2));
	if (!b)
		error_message(12, m);
	while (s[++i])
	{
		if (rows == 0 || rows == p->rows - 1)
			j = handle_first_last_row(s[i], b, j);
		else
			j = handle_middle_row(s, i, b, j);
	}
	j = fill_remaining_spaces(b, j, p, rows);
	b[j] = '1';
	b[j + 1] = '\0';
	return (b);
}

void	parse_point(t_data *m, t_parse *p)
{
	int	i;
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
			continue ;
		}
		fill_point(p->array[i], m, rows, &(p->point));
		rows++;
	}
}
