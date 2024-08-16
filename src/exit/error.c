#include "../include/cub3d.h"

void    error_message(int type, t_data *m)
{
	if (type == 0)
		ft_putstr_fd("Failed to allocate for memory\n", 2);
	else if (type == 1)
		ft_putstr_fd("Is a directory\n", 2);
	else if (type == 2)
		ft_putstr_fd("Invalid file entered\n", 2);
	else if (type == 3)
		ft_putstr_fd("Invalid texture\n", 2);
	else if (type == 4)
		ft_putstr_fd("Texture missing\n", 2);
	else if (type == 5)
		ft_putstr_fd("Invalid color\n", 2);
	else if (type == 6)
		ft_putstr_fd("Color is missing or Invalid color\n", 2);
	else if (type == 7)
		ft_putstr_fd("Invalid letter\n", 2);
	else if (type == 8)
		ft_putstr_fd("Error player position\n", 2);
	else if (type == 9)
		ft_putstr_fd("Map element has to be last and empty line can't be in between\n", 2);
	else if (type = 10)
		ft_putstr_fd("Player is on the border\n", 2);
	free_and_exit(m, 1);
}