#ifndef CUB3D
# define CUB3D

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "structs.h"
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>

void    manage_window(t_data *main);
void    error_message(int type, t_data *m);
void	validate_cmdline(char **av, t_data *m);
void	check_input(char **av, t_data *m);
void    free_and_exit(t_data *m, int num);
void    parse_map(t_data *main);
void    maptolayout(char *file_path, t_map *map, t_data *main, int fd);
void    init_map(t_map *map);
void	draw_map(t_data *main);

#endif