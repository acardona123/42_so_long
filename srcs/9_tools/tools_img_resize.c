/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_img_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:29:18 by acardona          #+#    #+#             */
/*   Updated: 2023/02/06 03:14:53 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Copy one pixel*/
static void	fts_cpy_pxl(char *pxl_src, char *pxl_dst, int bpp)
{
	int	i;

	i = -1;
	while (++i < bpp)
		pxl_dst[i] = pxl_src[i];
}

/*Increases the size of a square img (entier ratio of homotetie)*/
static void	fts_tools_resize_bigger(t_global *glo, t_data **img_src,
		int size_dst)
{
	t_data	*img_new;
	int		x;
	int		y;
	int		ratio;

	if ((*img_src)->line_length * 8 / (*img_src)->bpp == size_dst)
		return ;
	img_new = ft_tools_img_new(glo, size_dst, size_dst);
	if (img_new->bpp != (*img_src)->bpp)
		ft_garbage_group_free(&glo->garb.gbgroup, 1);
	ratio = size_dst * ((*img_src)->bpp / 8) / ((*img_src)->line_length);
	y = -1;
	while (++y < size_dst)
	{
		x = -1;
		while (++x < size_dst)
			fts_cpy_pxl(ft_tools_pxl_addr(*img_src, x / ratio, y / ratio),
				ft_tools_pxl_addr(img_new, x, y), (*img_src)->bpp);
	}
	ft_garbage_free_one(glo->garb.gbimg, *img_src);
	*img_src = img_new;
}

// /*Compress an image*/
// static void	fts_tools_resize_smaller(t_garbage *gbimg, void *mlx,
// 			t_data **img_src, int size_dst)
// {
// 	//to do =============================================================================
// }

void	ft_tools_resize_img(t_global *glo, t_data *img, int size)
{
	printf("bpp : %d\n", img->bpp);//
	printf("img_size : %d\nCHUNK_SIZE : %d\n", img->line_length, CHUNK_SIZE);//
	if (!glo || !img)
		ft_garbage_group_free(&glo->garb.gbgroup, 1);
	if (img->line_length * 8 / img->bpp == size)
		return ;
	if (img->line_length * 8 / img->bpp > size
		|| (size % (img->line_length * 8 / img->bpp) != 0))
	{
		write(1, "Error\nTexture size not dividor of CHUNK_SIZE:\n", 46);
		ft_garbage_group_free(&glo->garb.gbgroup, 1);
	}
	//should be managing 2 cases : resizing up or down
	fts_tools_resize_bigger(glo, (t_data **)&img, CHUNK_SIZE);
}
