/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_img_new_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:15 by acardona          #+#    #+#             */
/*   Updated: 2023/02/11 19:00:35 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Generate a pointer to a new img and fill its data*/
t_data	*ft_tools_img_new(t_global *glo, int width, int height)
{
	t_data	*new_data;
	void	*new_img;

	new_data = (t_data *)ft_my_malloc(glo->garb.gbptr, sizeof(t_data));
	new_img = mlx_new_image(glo->mlx, width, height);
	if (!new_img)
		ft_garbage_group_free(&glo->garb.gbgroup, ERR_MLX);
	ft_garbage_add(glo->garb.gbimg, new_img);
	new_data->addr = mlx_get_data_addr(new_img, &(new_data->bpp),
			&(new_data->line_length), &(new_data->endian));
	new_data->img = new_img;
	new_data->pix_width = width;
	new_data->pix_height = height;
	return (new_data);
}
