#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**layout;
	int		px;
	int		py;
	int		height;
}			t_map;

typedef struct	s_cur
{
	int x;
	int y;
} 			t_cur;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void 	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_len;
    int		endian;
	int		width;
	int		height;
	int		color;
}              t_window;

typedef	struct s_texture
{
	char *no;
	char *so;
	char *we;
	char *ea;
}			t_texture;

typedef struct s_color
{
	int	*r;
	int *g;
	int *b;
	int	*argb;
	int flag;
}			t_color;

typedef struct s_point
{
	char	*row;
	int		x_length;
	struct	s_point *next;
}			t_point;

typedef	struct s_player
{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double cameraX;
	double raydir_x;
	double raydir_y;
	double sideDistX;
	double sideDistX;
	double deltaDistX;
	double deltaDistY;
}		t_player;

typedef	struct s_parse
{
	char		*file_path;
	char		*buf;
	char		**array;
	int			encountered;
	int			max;
	int			rows;
	t_texture 	*texture;
	t_color		*color;
	t_point		*point;
}				t_parse;

typedef struct s_data
{
	t_parse		*parse;
	t_map		*map;
	t_window	*window;
	t_cur		*cur;
	t_player	*player;
}				t_data;

#endif