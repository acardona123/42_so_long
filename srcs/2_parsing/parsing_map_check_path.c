/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_check_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:54:18 by acardona          #+#    #+#             */
/*   Updated: 2023/02/02 21:38:45 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*ON MAP COPY: sub recursive searching of exit starting at p point*/
static int	fts_check_map_step(t_global *glo, char **map, t_coord p)
{
	int	find;

	if (map[p.y][p.x] == '1')
		return (0);
	if (map[p.y][p.x] == 'E')
		return (1);
	find = 0;
	map[p.y][p.x] = '1';
	if (p.x + 1 < glo->map_w - 1)
		find = fts_check_map_step(glo, map, (t_coord){p.x + 1, p.y});
	if (!find && p.y + 1 < glo->map_h - 1)
		find = fts_check_map_step(glo, map, (t_coord){p.x, p.y + 1});
	if (!find && p.x - 1 > 0)
		find = fts_check_map_step(glo, map, (t_coord){p.x - 1, p.y});
	if (!find && p.y - 1 > 0)
		find = fts_check_map_step(glo, map, (t_coord){p.x, p.y - 1});
	return (find);
}

void	ft_parsing_check_map_path(t_global *glo, char **map, char debug)
{
	t_coord	start;
	char	**map_cpy;
	int		y;
	int		find;

	map_cpy = ft_my_malloc(glo->garb.gbptr, sizeof(char *) * glo->map_h);
	start = ft_tools_find_map_elem(glo, map_cpy, 'E');
	y = 0;
	while (y < glo->map_h - 1)
	{
		map_cpy[y] = ft_my_malloc(glo->garb.gbptr,
				sizeof(char) * (ft_strlen(map[y]) + 1));
		ft_strlcpy(map_cpy[y], (const char *)map[y], ft_strlen(map[y]) + 1);
	}
	find = fts_check_map_step(glo, map_cpy, start);
	while (y >= 0)
		ft_garbage_free_one(glo->garb.gbptr, map_cpy[y]);
	ft_garbage_free_one(glo->garb.gbptr, map_cpy);
	if (!find)
		ft_parsing_map_error(&glo->garb.gbgroup, 6);
	if (debug)
		write(1, "  -path to exit : ok\n", 21);
}
