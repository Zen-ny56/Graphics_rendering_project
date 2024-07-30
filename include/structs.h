#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char **layout;
	int		width;
	int		height;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_map 	*map;
}              t_window;

#endif