#include "../include/cub3d.h"

void	free_array(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_texture(t_texture *t)
{
	if (t)
	{
		if (t->no)
			free(t->no);
		if (t->so)
			free(t->so);
		if (t->ea)
			free(t->ea);
		if (t->we)
			free(t->we);
	}
}

void	free_color(t_color *c)
{
	if (c)
	{
		if (c->r)
			free(c->r);
		if (c->g)
			free(c->g);
		if (c->b)
			free(c->b);
		if (c->argb)
			free(c->argb);
	}
}

void	free_point(t_point *p)
{
	t_point *tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp->row);
		tmp->row = NULL;
		free(tmp);
	}
}

void	free_par(t_parse *parse)
{
	if (parse)
	{
		if (parse->file_path)
			free(parse->file_path);
		if (parse->buf)
			free(parse->buf);
		if (parse->array)
			free_array(parse->array);
		if (parse->texture)
			free_texture(parse->texture);
		if (parse->color)
			free_color(parse->color);
		if (parse->point)
			free_point(parse->point);
		free(parse);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->layout)
			free_array(map->layout);
		free(map);
	}
}

void	free_and_exit(t_data *data, int num)
{
	if (data)
	{
		// Free player structure
		if (data->player)
		{
			printf("Here\n");
			free(data->player);
			data->player = NULL;
		}
		// Free map structure and its contents
		if (data->map)
		{
			free_map(data->map);
			data->map = NULL;
		}

		// Free parse structure and its contents
		if (data->parse)
		{
			free_par(data->parse);
			data->parse = NULL;
		}

		// Free the data structure itself
		free(data);
		data = NULL;
		if (num >= 0)
		{
			if (num == 1)
				exit(EXIT_FAILURE);
			else if (num == 0)
				exit(EXIT_SUCCESS);
		}
	}
}
