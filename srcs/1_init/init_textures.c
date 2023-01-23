/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:16:13 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 02:57:25 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*add a texture to the texturepack(relative path). dst elem of struct textures*/
static int	fts_init_textures_tail_init(t_global glo, t_texture_tail **dst,
		char *path)
{
	(*dst)->path = path;
	(*dst)->data->img = mlx_xpm_file_to_image(glo.mlx, path,
			&(*dst)->img_width, &(*dst)->img_width);
	if (!(*dst)->data->img)
	{
		write(1, "Texture not found. Execution aborted.\n", 38);
		ft_garbage_group_free(&glo.garb.gbgroup, 1);
	}
	ft_garbage_add(glo.garb.gbimg, (*dst)->data->img);
	(*dst)->data->addr = mlx_get_data_addr((*dst)->data->img,
			&(*dst)->data->bits_per_pixel,
			&(*dst)->data->line_length, &(*dst)->data->endian);
	return (0);
}

/*register all the textures (saved in garbage)*/
void	ft_init_textures_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> textures init :\n", 19);
	fts_init_textures_tail_init(*glo, &(glo->textures->exit), PATH_EXIT);
	fts_init_textures_tail_init(*glo, &(glo->textures->ground), PATH_GROUND);
	fts_init_textures_tail_init(*glo, &(glo->textures->player), PATH_PLAYER);
	fts_init_textures_tail_init(*glo, &(glo->textures->wall), PATH_WALL);
	fts_init_textures_tail_init(*glo, &(glo->textures->fruit), PATH_FRUIT);
	if (debug)
		write(1, " ok\n", 4);
}
