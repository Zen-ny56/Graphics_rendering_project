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
void	parse_texture(t_data *m, t_parse *p);
bool    check_dir(char *arg);
void    init_parse(t_parse *parse);
void	init_texture(t_texture *t);
void	init_main(t_data *m);
void    parse_color(t_data *m, t_parse *p);
void	init_color(t_color *c);
void	store_color(char *s, t_color *c, t_data *m, int	k);
void    parse_point(t_data *m, t_parse *p);
void    pointolayout(t_data *main, t_parse *p, t_point *po);
void    setplayerposition(int y, t_map *map, t_data *m);

#endif