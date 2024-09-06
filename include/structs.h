#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**layout;
	int		py;
	int		px;
	int		mapX;
	int		mapY;
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
	int		tex_w;
	int		tex_h;
	int		tex_w1;
	int		tex_h1;
	int		tex_w2;
	int		tex_h2;
	int		tex_w3;
	int		tex_h3;
	int		tex_w4;
	int		tex_h4;
	void	*cnv_img1;
	int		*cnv_addr1;
	int		cnv_bpp1;
	int		cnv_ll1;
	int		cnv_en1;
	void	*cnv_img2;
	int		*cnv_addr2;
	int		cnv_bpp2;
	int		cnv_ll2;
	int		cnv_en2;
	void	*cnv_img3;
	int		*cnv_addr3;
	int		cnv_bpp3;
	int		cnv_ll3;
	int		cnv_en3;
	void	*cnv_img4;
	int		*cnv_addr4;
	int		cnv_bpp4;
	int		cnv_ll4;
	int		cnv_en4;
	int		texx;
	int		texy;
	double	texX;
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
	int	cflag; // 0 means floor color is first else start with ceiling
	int floor_color;
	int	ceiling_color;
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
	double angle;
	double pixel_width;
	double pixel_height;
	double plane_length;
	double plane_x;
	double plane_y;
	double cameraX;
	double raydir_x;
	double raydir_y;
	double sideDistX;
	double sideDistY;
	double perpWallDist;
	int	   stepX;
	int	   stepY;
	int	   side;
	double deltaDistX;
	double deltaDistY;
	double endRayY;
	double endRayX;
}		t_player;

typedef	struct s_parse
{
	char		*file_path;
	char		*buf;
	char		**array;
	int			tile_size;
	int			encountered;
	int			max;
	int			rows;
	t_texture 	*texture;
	t_color		*color;
	t_point		*point;
}				t_parse;

typedef struct s_wall
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	double	wallX;
}			t_wall;

typedef struct s_data
{
	t_parse		*parse;
	t_map		*map;
	t_window	*window;
	t_cur		*cur;
	t_player	*player;
	t_wall		*wall;
}				t_data;

#endif