/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map_texture_select.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:53:56 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 02:18:49 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*for a chunck (x, y) of map, returns the t_data texture associated*/
t_data	*ft_chunk_texture_selec(t_global *glo, int x, int y)
{
	if ((glo->map)[y][x] == '1')
		return (&glo->textures.wall->data);
	else if ((glo->map)[y][x] == '0' || (glo->map)[y][x] == 'P')
		return (&glo->textures.ground->data);
	else if ((glo->map)[y][x] == 'E')
		return (&glo->textures.exit_lock->data);
	else if ((glo->map)[y][x] == 'C')
		return (&glo->textures.col_on->data);
	else if ((glo->map)[y][x] == 'c')
		return (&glo->textures.col_off->data);
	else
		ft_garbage_group_free(&glo->garb.gbgroup, 1);
	return (0);
}
