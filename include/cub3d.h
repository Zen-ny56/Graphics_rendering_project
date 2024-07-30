#ifndef CUB3D
# define CUB3D

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "structs.h"
# include <math.h>
# include <stdio.h>
# include <stdint.h>

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>

void    manage_window(t_window *ups);
void    error_message(int type, t_data *m);
void	validate_cmdline(char **av, t_data *m);
void	check_input(char **av, t_data *m);
void    free_and_exit(t_data *m, int num);

#endif