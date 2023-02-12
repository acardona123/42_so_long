/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_img_get_coords.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:32:44 by acardona          #+#    #+#             */
/*   Updated: 2023/02/06 02:42:55 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Returns the address of a pixel described by its coordonates*/
char	*ft_tools_get_pxl_addr(t_data *data, int x, int y)
{
	char	*rtn;

	if (!data || data->bpp == 0 || !data->addr
		|| data->line_length == 0)
	{
		write(1, "Error\nIn ft_tools_get_pxl_addr.\n", 32);
		return (0);
	}
	rtn = data->addr + data->line_length * data->bpp / 8 * y
		+ x * data->bpp / 8;
	return (rtn);
}