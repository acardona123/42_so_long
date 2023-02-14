/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_pxl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:43:58 by acardona          #+#    #+#             */
/*   Updated: 2023/02/13 21:41:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Returns the address of a pixel described by its coordonates*/
char	*ft_tools_pxl_addr(t_data *data, int x, int y)
{
	char	*rtn;

	if (!data || data->bpp == 0 || !data->addr
		|| data->line_length == 0)
	{
		write(1, "Error\nIn ft_tools_get_pxl_addr.\n", 32);
		return (0);
	}
	rtn = data->addr + data->line_length * y + x * data->bpp / 8;
	return (rtn);
}

/*Apply the given color to the pixel (x,y) of an image*/
void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = ft_tools_pxl_addr(data, x, y);
	*(unsigned int *)dst = color;
}
