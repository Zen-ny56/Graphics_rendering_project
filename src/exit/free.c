#include "../include/cub3d.h"

void    free_par(t_parse *parse)
{
	if (parse->file_path)
	{
		free(parse->file_path);
		parse->file_path = NULL;
	}
}

void    free_and_exit(t_data *m, int num)
{
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