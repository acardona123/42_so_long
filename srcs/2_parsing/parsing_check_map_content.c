/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:48:39 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 01:38:54 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Check the content of each line (border walls, components)*/
static int	fts_check_line(char *line, char border, int contain[3], int map_w)
{
	int	x;

	if ((int)ft_strlen((const char *)line) != map_w)
		return (1);
	x = -1;
	while (line[++x])
	{
		if (border || x == 0 || x == map_w - 1)
		{
			if (line[x] != '1')
				return (2);
		}
		else
		{
			if (line[x] != 'E' && line[x] != 'P' && line[x] != 'C'
				&& line[x] != '0' && line[x] != '1')
				return (3);
			if ((line[x] == 'E' && ++contain[0] > 1)
				|| (line[x] == 'P' && ++contain[1] > 1))
				return (4);
			else if (line[x] == 'C')
				contain[2] += 1;
		}
	}
	return (0);
}

void	ft_parsing_check_map_content(t_global *glo)
{
	int		*contain;
	int		y;
	int		error;

	glo->map_w = ft_strlen((const char *)(*(glo->map)));
	contain = (int [3]){'\0', '\0', '\0'};
	error = fts_check_line((glo->map)[glo->map_h - 1], 1, contain, glo->map_w);
	y = glo->map_h - 2;
	while (!error && y > 0)
	{
		error = fts_check_line((glo->map)[y], 0, contain, glo->map_w);
		y--;
	}
	if (!error)
		error = fts_check_line(*(glo->map), 1, contain, glo->map_w);
	if (!error && (!contain[0] || !contain[1] || !contain[2]))
		error = 5;
	ft_parsing_map_error(&glo->garb.gbgroup, error);
	glo->cpt_col = contain[3];
	if (DEBUG)
		write(1, "  -map content : ok\n", 21);
}
