#include "../include/cub3d.h"

void	set_win_values(t_window *ups)
{
	ups->mlx = mlx_init();
	if (!ups->mlx)
	{
		printf("Failed to initialise mlx lib\n");
		exit(1);
	}
	ups->window = NULL;
	ups->width = 800;
	ups->height = 600;
}

int	exit_window(t_window *ups)
{
	mlx_clear_window(ups->mlx, ups->window);
	mlx_destroy_window(ups->mlx, ups->window);
 	ft_putstr_fd("Window exited\n", 1);
	exit(0);
}

int	keypress(int keycode, t_window *ups)
{
	if (keycode == 53)
	{
		if (exit_window(ups) == 0)
			exit(0);
	}
	return (0);
}

int handle_close(void *param)
{
	t_window *ups = (t_window *)param;
	return (exit_window(ups));
}

void	create_window(t_window *ups)
{
	ups->window = mlx_new_window(ups->mlx, ups->width, ups->height, "Mini-Map Window");
	if (!ups->window)
	{
		printf("Failed to create the window\n");
		exit(1);
	}
}

void    manage_window(t_window *ups)
{
	set_win_values(ups);
	create_window(ups);
	mlx_hook(ups->window, 02, 1L << 0, keypress, ups);
	mlx_hook(ups->window, 17, 1L << 0, handle_close, ups);
	mlx_loop(ups->mlx);
}