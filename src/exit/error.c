#include "../include/cub3d.h"

void    error_message(int type, t_data *m)
{
	if (type == 0)
		ft_putstr_fd("Failed to allocate for memory", 2);
	else if (type == 1)
		ft_putstr_fd("Is a directory", 2);
	else if (type == 2)
		ft_putstr_fd("Invalid file entered", 2);
	free_and_exit(m, 1);
}