#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char **layout;
	int		width;
	int		height;
}			t_map;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
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