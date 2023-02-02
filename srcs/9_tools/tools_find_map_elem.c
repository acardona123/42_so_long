/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_find_map_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:02:22 by acardona          #+#    #+#             */
/*   Updated: 2023/02/02 20:02:53 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Return the coordonates of the starting point of the content-verified map */
t_coord	ft_tools_find_map_elem(t_global *glo, char **map, char elem)
{
	int	x;
	int	y;

	y = 1;
	while (y < glo->map_h - 2)
	{
		x = 1;
		while (x < glo->map_w - 2)
		{
			if (map[y][x] == elem)
				return ((t_coord){x, y});
			x++;
		}
		y++;
	}
	ft_error_exit(&glo->garb.gbgroup, 1, "Element searched not find in map.");
	return ((t_coord){-1, -1});
}