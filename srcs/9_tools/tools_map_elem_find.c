/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map_elem_find.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:02:22 by acardona          #+#    #+#             */
/*   Updated: 2023/02/03 13:44:19 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Return the coordonates of the starting point of the content-verified map */
void	ft_tools_elem_find(t_global *glo, char **map, char elem, t_coord *dst)
{
	int	x;
	int	y;

	y = 0;
	while (++y < glo->map_h - 1)
	{
		x = 0;
		while (++x < glo->map_w - 1)
		{
			if ((map[y])[x] == elem)
			{
				dst->x = x;
				dst->y = y;
				return ;
			}
		}
	}
	ft_error_exit(&glo->garb.gbgroup, 1, "Element searched not find in map.");
	*dst = (t_coord){-1, -1};
}
