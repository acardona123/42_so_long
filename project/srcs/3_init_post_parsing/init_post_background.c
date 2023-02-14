/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:21:50 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:22:01 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*generate the t_data associated to the background based on the map*/
void	ft_init_post_background_init(t_global *glo)
{
	int		x;
	int		y;
	t_data	*chunk_texture;

	if (DEBUG)
		write(1, "=> background init :\n", 21);
	glo->background = ft_tools_img_new(glo, glo->map_w * CHUNK_SIZE,
			glo->map_h * CHUNK_SIZE);
	y = -1;
	while (++y < glo->map_h)
	{
		x = -1;
		while (++x < glo->map_w)
		{
			chunk_texture = ft_chunk_texture_selec(glo, x, y);
			ft_tools_img_blend(glo->background, chunk_texture,
				x * CHUNK_SIZE, y * CHUNK_SIZE);
		}
	}
	if (DEBUG)
		write(1, " ok\n", 4);
}
