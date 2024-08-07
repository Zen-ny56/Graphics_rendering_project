/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:12:36 by naadam            #+#    #+#             */
/*   Updated: 2024/08/07 16:10:39 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

// void	set_win_values(t_window *ups)
// {
// 	ups->mlx = mlx_init();
// 	if (!ups->mlx)
// 	{
// 		printf("Failed to initialise mlx lib\n");
// 		exit(1);
// 	}
// 	ups->window = NULL;
// 	ups->addr = NULL;
// 	ups->width = 800;
// 	ups->height = 600;
// }

// int	exit_window(t_window *ups)
// {
// 	mlx_clear_window(ups->mlx, ups->window);
// 	mlx_destroy_window(ups->mlx, ups->window);
//  	ft_putstr_fd("Window exited\n", 1);
// 	exit(0);
// }

// int	keypress(int keycode, t_window *ups)
// {
// 	if (keycode == 53)
// 	{
// 		if (exit_window(ups) == 0)
// 			exit(0);
// 	}
// 	return (0);
// }

// int handle_close(void *param)
// {
// 	t_window *ups = (t_window *)param;
// 	return (exit_window(ups));
// }

// void	create_window(t_window *ups)
// {
// 	ups->window = mlx_new_window(ups->mlx, ups->width, ups->height, "Mini-Map Window");
// 	ups->img = mlx_new_image(ups->mlx, ups->width, ups->height);
// 	if (!ups->img)
// 		printf("Error\n");
// 	ups->addr = mlx_get_data_addr(ups->img, &ups->bits_per_pixel, &ups->line_len,
// 		&ups->endian);
// 	if (!ups->addr)
// 		printf("Error\n");
// }

// void    manage_window(t_data *main)
// {
// 	main->window = malloc(sizeof(t_window));
// 	if (!main->window)
// 	{
// 		main->type = 0;
// 		error_message(main->type, main);
// 	}
// 	set_win_values(main->window);
// 	create_window(main->window);
// 	parse_map(main);
// 	draw_map(main);
// 	// mlx_put_image_to_window(main->window->mlx, main->window->window, main->window->img, 0, 0);
// 	mlx_hook(main->window->window, 02, 1L << 0, keypress, main->window);
// 	mlx_hook(main->window->window, 17, 1L << 0, handle_close, main->window);
// 	mlx_loop(main->window->mlx);
// }