/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:23:50 by naadam            #+#    #+#             */
/*   Updated: 2024/09/12 01:12:11 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

const char	*skip_prefixes_and_whitespace(const char *path)
{
	while (*path == ' ' || *path == '\t' || *path == 'N' || *path == 'O'
		|| *path == 'S' || *path == 'E' || *path == 'W' || *path == '/')
	{
		if (*path == ' ' || *path == '\t')
			path++;
		else
		{
			if (strncmp(path, "NO", 2) == 0 || strncmp(path, "SO", 2) == 0
				|| strncmp(path, "WE", 2) == 0 || strncmp(path, "EA", 2) == 0)
			{
				path += 2;
				while (*path == ' ' || *path == '\t')
					path++;
				break ;
			}
			else
				break ;
		}
	}
	return (path);
}

char	*allocate_and_copy_path(const char *path)
{
	char	*cleaned_path;

	cleaned_path = malloc(strlen(path) + 1);
	if (!cleaned_path)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	strcpy(cleaned_path, path);
	return (cleaned_path);
}

char	*clean_texture_path(const char *path)
{
	const char	*cleaned_start;

	cleaned_start = skip_prefixes_and_whitespace(path);
	return (allocate_and_copy_path(cleaned_start));
}

void	store_textures(t_texture *t, t_window *w)
{
	char	*no_cleaned;
	char	*so_cleaned;
	char	*we_cleaned;
	char	*ea_cleaned;

	no_cleaned = clean_texture_path(t->no);
	so_cleaned = clean_texture_path(t->so);
	we_cleaned = clean_texture_path(t->we);
	ea_cleaned = clean_texture_path(t->ea);
	w->cnv_img1 = mlx_xpm_file_to_image(w->mlx, no_cleaned,
			&w->tex_w1, &w->tex_h1);
	w->cnv_img2 = mlx_xpm_file_to_image(w->mlx, so_cleaned,
			&w->tex_w2, &w->tex_h2);
	w->cnv_img3 = mlx_xpm_file_to_image(w->mlx, we_cleaned,
			&w->tex_w3, &w->tex_h3);
	w->cnv_img4 = mlx_xpm_file_to_image(w->mlx, ea_cleaned,
			&w->tex_w4, &w->tex_h4);
	free(no_cleaned);
	free(so_cleaned);
	free(we_cleaned);
	free(ea_cleaned);
}

void	add_textures(t_data *m, t_window *w, t_parse *p)
{
	(void)m;
	store_textures(p->texture, w);
	get_textures_add(w);
	if (!w->cnv_addr1 || !w->cnv_addr2 || !w->cnv_addr3 || !w->cnv_addr4)
		exit(1);
}
