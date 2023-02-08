/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_img_sub_cpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:28:47 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 00:06:37 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*cpy rectangle (dimensions given)from img dst{co_src} to img dst{do_dst}. */
void	ft_tools_img_sub_cpy(t_img_cpy cpy)
{
	int	x;
	int	y;
	int	p;

	y = -1;
	while (++y < cpy.cpy_h
		&& cpy.co_dst.y + y < ((t_img *)(cpy.img_dst->img))->height
		&& cpy.co_src.y + y < ((t_img *)(cpy.img_src->img))->height)
	{
		x = -1;
		while (++x < cpy.cpy_w
			&& cpy.co_dst.x + x < ((t_img *)(cpy.img_dst->img))->width
			&& cpy.co_src.y + y < ((t_img *)(cpy.img_src->img))->width)
		{
			p = -1;
			while (++p < cpy.img_dst->bpp)
			{
				(ft_tools_pxl_addr(cpy.img_dst, cpy.co_dst.x + x,
						cpy.co_dst.y + y))[p] = (ft_tools_pxl_addr(cpy.img_src,
						cpy.co_src.x + x, cpy.co_src.y + y))[p];
			}
		}
	}
}
