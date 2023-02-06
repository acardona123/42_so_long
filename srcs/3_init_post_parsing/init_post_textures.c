/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:16:13 by acardona          #+#    #+#             */
/*   Updated: 2023/02/06 03:33:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*add a texture to the texturepack(relative path). dst elem of struct textures*/
static int	fts_init_textures_tail_init(t_global *glo, t_texture_tail **dst,
		char *path)
{
	int	endian;

	*dst = ft_my_malloc(glo->garb.gbptr, sizeof(t_texture_tail));
	(*dst)->path = path;
	(*dst)->data.img = mlx_xpm_file_to_image(glo->mlx, path,
			&(*dst)->img_width, &(*dst)->img_width);
	if (!(*dst)->data.img)
	{
		write(1, "Texture not found. Execution aborted.\n", 38);
		ft_garbage_group_free(&glo->garb.gbgroup, ERR_MLX);
	}
	ft_garbage_add(glo->garb.gbimg, (*dst)->data.img);
	(*dst)->data.addr = mlx_get_data_addr((*dst)->data.img,
			&(*dst)->data.bpp,
			&(*dst)->data.line_length, &(*dst)->data.endian);
	endian = (*dst)->data.endian;
	ft_tools_resize_img(glo, &(*dst)->data, CHUNK_SIZE);
	(*dst)->img_width = CHUNK_SIZE;
	(*dst)->img_height = CHUNK_SIZE;
	(*dst)->data.endian = endian;
	return (0);
}

/*register all the textures (saved in garbage)*/
void	ft_init_post_textures_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> textures init :\n", 19);
	fts_init_textures_tail_init(glo, &(glo->textures.exit), PATH_EXIT);
	fts_init_textures_tail_init(glo, &(glo->textures.ground), PATH_GROUND);
	fts_init_textures_tail_init(glo, &(glo->textures.player), PATH_PLAYER);
	fts_init_textures_tail_init(glo, &(glo->textures.wall), PATH_WALL);
	fts_init_textures_tail_init(glo, &(glo->textures.fruit), PATH_COLLECT);
	if (debug)
		write(1, " ok\n", 4);
}
