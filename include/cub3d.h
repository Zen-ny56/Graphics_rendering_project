#ifndef CUB3D
# define CUB3D

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#define GAP_SIZE 1
#define MOVE_SPEED 1.75
#define PI 3.14159265358979323846
#define FOV (PI / 3)
#define M_WIDTH 600
#define M_HEIGHT 600
#define EPSILON 1e-6

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
void    init_color(t_color *c);
void	init_main(t_data *m);
void    parse_color(t_data *m, t_parse *p);
void	color(t_color *c);
void	store_color(char *s, t_color *c, t_data *m, int	k);
void    parse_point(t_data *m, t_parse *p);
void    pointolayout(t_data *main, t_parse *p, t_point *po);
void    setplayerposition(int y, t_map *map, t_data *m);
int     setmaxwidth(t_parse *p);
void    find_max(t_parse *p);
int	    islineempty(const char *line);
int	    precheckinterference(char *s);
void	count_rows(t_parse *p);
void	checkboundaries(t_data *m, t_cur *cur, t_map *map);
void	add_coordinatestruct(char **layout, t_data *m, int y);
void    execution(t_data *main);
void    draw_minimap(t_data *m);
void    mark_player(t_data *data, int x, int y, t_parse *p);
void	my_mlx_pixel_put(t_window *win, int x, int y, int color);
void    draw_player(t_window *w, t_player *player, int tile_size);
int     keypress(int keycode, t_data *m);
int     exit_window(t_data *m);
void    draw_grid(t_data *m);
void	raycasting(t_data *main);
void    draw(t_data *m, t_map *map, t_cur *cur, t_parse *p);
void	set_tilesize(t_parse *parse);
void	set_raydir(t_player *player, t_window *window, t_data *m);
void    add_textures(t_data *m, t_window *w, t_parse *p);
void	texture_prep(t_data *data);
int     get_color(t_data *data, int tex_y);

#endif