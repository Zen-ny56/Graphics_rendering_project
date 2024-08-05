#include "../include/cub3d.h"

void    free_par(t_parse *parse)
{
	if (parse->file_path)
	{
		free(parse->file_path);
		parse->file_path = NULL;
	}
}

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
}

void	free_map(t_map *map)
{
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