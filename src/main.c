#include "../include/cub3d.h"

int main(int ac, char **av)
{
	//Allocation for main structure
	if (ac > 2 || ac < 2)
		return (printf("Wrong input. Usage (./Cub3d ./maps/x.cub)\n"), 1);
	t_data *main_struct;
	main_struct = malloc(sizeof(t_data));
	if (!main_struct)                  
		return (-1);
	init_main(main_struct);
	validate_cmdline(av, main_struct);
	execution(main_struct);
}