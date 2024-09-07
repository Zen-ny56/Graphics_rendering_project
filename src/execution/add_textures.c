/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:23:50 by naadam            #+#    #+#             */
/*   Updated: 2024/09/07 20:40:08 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	store_textures(t_texture *t, t_window *w)
{
	(void)t;
	w->cnv_img1 = mlx_xpm_file_to_image(w->mlx, "./textures/dali.xpm", &w->tex_w1, &w->tex_h1);
	w->cnv_img2 = mlx_xpm_file_to_image(w->mlx, "./textures/Judith.xpm", &w->tex_w2, &w->tex_h2);
	w->cnv_img3 = mlx_xpm_file_to_image(w->mlx, "./textures/Night.xpm", &w->tex_w3, &w->tex_h3);
	w->cnv_img4 = mlx_xpm_file_to_image(w->mlx, "./textures/Pearl.xpm", &w->tex_w4, &w->tex_h4);
}

void get_textures_add(t_window *w)
{
	if (w->cnv_img1)
		w->cnv_addr1 = (int *)mlx_get_data_addr(w->cnv_img1, &w->cnv_bpp1, &w->cnv_ll1, &w->cnv_en1);
	else
		fprintf(stderr, "Texture image 1 not loaded\n");
	if (w->cnv_img2)
		w->cnv_addr2 = (int *)mlx_get_data_addr(w->cnv_img2, &w->cnv_bpp2, &w->cnv_ll2, &w->cnv_en2);
	else
		fprintf(stderr, "Texture image 2 not loaded\n");
	if (w->cnv_img3)
		w->cnv_addr3 = (int *)mlx_get_data_addr(w->cnv_img3, &w->cnv_bpp3, &w->cnv_ll3, &w->cnv_en3);
	else
		fprintf(stderr, "Texture image 3 not loaded\n");
	if (w->cnv_img4)
		w->cnv_addr4 = (int *)mlx_get_data_addr(w->cnv_img4, &w->cnv_bpp4, &w->cnv_ll4, &w->cnv_en4);
	else
		fprintf(stderr, "Texture image 4 not loaded\n");
}

void    add_textures(t_data *m, t_window *w, t_parse *p)
{
	(void)m;
	store_textures(p->texture, w);
	get_textures_add(w);
	if (!w->cnv_addr1 || !w->cnv_addr2 || !w->cnv_addr3 || !w->cnv_addr4)
		exit(1);
}