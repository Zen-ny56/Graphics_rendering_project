#include "../include/cub3d.h"

void 	free_array(char **s)
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
	if (t->no)
		free(t->no);
	if (t->so)
		free(t->so);
	if (t->ea)
		free(t->ea);
	if (t->we)
		free(t->we);
}
void    free_par(t_parse *parse)
{
	if (parse->file_path)
		free(parse->file_path);
	if (parse->buf)
		free(parse->buf);
	if (parse->array)
		free_array(parse->array);
	if (parse->texture)
		free_texture(parse->texture);
	// if (parse->color)
	// 	free_color(parse->color);
	// if (parse->point)
	// 	free_point(parse->point);
}


void	free_map(t_map *map)
{
	if (map->layout)
		free_array(map->layout);
	free(map);
}

void    free_and_exit(t_data *m, int num)
{
	if (m->map)
		free_map(m->map);
	if (m->parse)
		free_par(m->parse);
	if (m)
		free(m);
	if (num > 0)
	{
		if (num == 1)
			exit(EXIT_FAILURE);
		else if (num == 0)
			exit(EXIT_SUCCESS);
	}
}