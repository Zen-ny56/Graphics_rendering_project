/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:01:16 by naadam            #+#    #+#             */
/*   Updated: 2024/09/11 23:03:13 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*main_struct;

	if (ac > 2 || ac < 2)
		return (printf("Wrong input. Usage (./Cub3d ./maps/x.cub)\n"), 1);
	main_struct = malloc(sizeof(t_data));
	if (!main_struct)
		return (-1);
	init_main(main_struct);
	validate_cmdline(av, main_struct);
	execution(main_struct);
}
