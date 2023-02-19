/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map_elem_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:44:27 by acardona          #+#    #+#             */
/*   Updated: 2023/02/03 14:22:26 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Count the number of apparition of the char elem in the map*/
long int	ft_tools_elem_count(char **map, char elem)
{
	int	y;
	int	x;
	int	cpt;

	if (!map)
		return (0);
	cpt = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == elem)
				cpt++;
	}
	return (cpt);
}
