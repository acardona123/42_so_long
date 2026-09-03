/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_img_draw_rec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:31:18 by acardona          #+#    #+#             */
/*   Updated: 2023/02/13 21:31:49 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*draw a rectangle (given dimension) on image starting at given position*/
void	ft_tools_img_draw_rec(t_data *dst, int color, t_coord pos, t_coord dim)
{
	int	ix;
	int	iy;
	int	*ptr;

	if (dst->bpp != sizeof(int) * 8)
		write(1, "Error\npb fts_init_rect, pixel != int\n", 37);
	iy = -1;
	while (++iy < dim.y)
	{
		ptr = (int *) ft_tools_pxl_addr(dst, pos.x, pos.y + iy);
		ix = -1;
		while (++ix < dim.x)
		{
			*ptr = color;
			ptr++;
		}
	}
}
