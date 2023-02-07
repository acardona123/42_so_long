/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:21:50 by acardona          #+#    #+#             */
/*   Updated: 2023/02/07 01:54:47 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*for a chunck (x, y) of map, returns the t_data texture associated*/
static t_data	*fts_chunk_texture_select(t_global *glo, int x, int y)
{
	if ((glo->map)[y][x] == '1')
		return (&glo->textures.wall->data);
	else if ((glo->map)[y][x] == '0' || (glo->map)[y][x] == 'P')
		return (&glo->textures.ground->data);
	else if ((glo->map)[y][x] == 'E')
		return (&glo->textures.exit->data);
	else if ((glo->map)[y][x] == 'C')
		return (&glo->textures.coll->data);
	else
		ft_garbage_group_free(&glo->garb.gbgroup, 1);
	return (0);
}

/*generate the t_data associated to the background based on the map*/
void	ft_init_post_background_init(t_global *glo, char debug)
{
	int		x;
	int		y;
	t_data	*chunk_texture;

	if (debug)
		write(1, "=> background init :\n", 21);
	glo->background = ft_tools_img_new(glo, glo->map_w * CHUNK_SIZE,
			glo->map_h * CHUNK_SIZE);
	y = -1;
	while (++y < glo->map_h)
	{
		x = -1;
		while (++x < glo->map_w)
		{
			chunk_texture = fts_chunk_texture_select(glo, x, y);
			ft_tools_img_blend(glo->background, chunk_texture,
				x * CHUNK_SIZE, y * CHUNK_SIZE);
		}
	}
	if (debug)
		write(1, " ok\n", 4);
}
