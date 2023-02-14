/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:16:13 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 02:56:17 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*add a texture to the texturepack(relative path). dst elem of struct textures*/
static void	fts_init_textures_tail_init(t_global *glo, t_texture_tail **dst,
		char *path, unsigned int resize)
{
	int	endian;

	*dst = ft_my_malloc(glo->garb.gbptr, sizeof(t_texture_tail));
	(*dst)->path = path;
	(*dst)->data.img = mlx_xpm_file_to_image(glo->mlx, path,
			&(*dst)->data.pix_width, &(*dst)->data.pix_height);
	if (!(*dst)->data.img)
	{
		write(1, "Error\nTexture not found. Execution aborted.\n", 44);
		ft_garbage_group_free(&glo->garb.gbgroup, ERR_MLX);
	}
	ft_garbage_add(glo->garb.gbimg, (*dst)->data.img);
	(*dst)->data.addr = mlx_get_data_addr((*dst)->data.img,
			&((*dst)->data.bpp),
			&((*dst)->data.line_length), &((*dst)->data.endian));
	endian = (*dst)->data.endian;
	if (resize != 0)
	{
		ft_tools_resize_img(glo, &((*dst)->data), resize);
		(*dst)->img_width = resize;
		(*dst)->img_height = resize;
		(*dst)->data.pix_height = resize;
		(*dst)->data.pix_width = resize;
	}
	(*dst)->data.endian = endian;//revoir gestion endian
}

/*register all the textures (saved in garbage)*/
void	ft_init_post_textures_init(t_global *glo)
{
	if (DEBUG)
		write(1, "=> textures init :\n", 19);
	fts_init_textures_tail_init(glo, &(glo->textures.exit_lock),
		PATH_EXIT_LOCK, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.exit_open),
		PATH_EXIT_OPEN, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.ground),
		PATH_GROUND, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.player),
		PATH_PLAYER, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.wall),
		PATH_WALL, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.col_on),
		PATH_COL_ON, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.col_off),
		PATH_COL_OFF, CHUNK_SIZE);
	fts_init_textures_tail_init(glo, &(glo->textures.stat_sign),
		PATH_SIGN, 0);
	fts_init_textures_tail_init(glo, &(glo->textures.victory),
		PATH_VICTORY, ft_tools_min_int(WIN_WIDTH, WIN_HEIGHT) / 48 * 48);
	if (DEBUG)
		write(1, " ok\n", 4);
}
