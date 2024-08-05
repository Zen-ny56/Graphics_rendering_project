#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char **layout;
	unsigned int	width;// Width of all columns
	unsigned int	height;// No. of columns
	unsigned int	player_x; // Player's starting x position
	unsigned int	player_y; // Player's starting y position
}			t_map;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void 	*img;
    char	 *addr;
    int		bits_per_pixel;
    int		line_len;
    int		endian;
	int		width;
	int		height;
	int		color;
}              t_window;

typedef struct s_parse
{
	char	*file_path;
	char	*file;
}				t_parse;

typedef enum s_etype
{
	MEM_ALLOC,
	DIRECTORY,
	INVALID_FILE,
}			t_etype;


typedef struct s_data
{
	t_etype 	type;	
	t_parse		*parse;
	t_map		*map;
	t_window	*window;
}				t_data;

#endif