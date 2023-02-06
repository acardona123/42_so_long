/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:54:18 by acardona          #+#    #+#             */
/*   Updated: 2023/02/03 14:31:57 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*ON MAP COPY: sub recursive searching of exit starting at p point*/
static void	fts_check_map_step(t_global *glo, char **map, t_coord p,
		long int sum[2])
{
	if (map[p.y][p.x] == '1')
		return ;
	if (map[p.y][p.x] == 'E')
		sum[0] += 1;
	if (map[p.y][p.x] == 'C')
		sum[1] += 1;
	map[p.y][p.x] = '1';
	if (p.x + 1 < glo->map_w - 1 && map[p.y][p.x + 1] != 1)
		fts_check_map_step(glo, map, (t_coord){p.x + 1, p.y}, sum);
	if (p.y + 1 < glo->map_h - 1 && map[p.y + 1][p.x] != 1)
		fts_check_map_step(glo, map, (t_coord){p.x, p.y + 1}, sum);
	if (p.x - 1 > 0 && map[p.y][p.x - 1] != 1)
		fts_check_map_step(glo, map, (t_coord){p.x - 1, p.y}, sum);
	if (p.y - 1 > 0 && map[p.y - 1][p.x] != 1)
		fts_check_map_step(glo, map, (t_coord){p.x, p.y - 1}, sum);
}

/*Copy a map (src to dest)*/
static char	**fts_parsing_map_cpy(t_global *glo, char **map_src,
	int map_h)
{
	char	**map_dest;

	map_dest = ft_my_malloc(glo->garb.gbptr, sizeof(char *) * (map_h + 1));
	map_dest[map_h] = 0;
	while (--map_h >= 0)
	{
		map_dest[map_h] = ft_my_malloc(glo->garb.gbptr,
				sizeof(char) * (ft_strlen(map_src[map_h]) + 1));
		ft_strlcpy(map_dest[map_h], map_src[map_h],
			ft_strlen(map_src[map_h] + 1));
	}
	return (map_dest);
}

/*Free a map, used to free the copy of map*/
static void	fts_parsing_map_free(t_global *glo, char **map, int map_h)
{
	while (--map_h >= 0)
		ft_garbage_free_one(glo->garb.gbptr, map[map_h]);
	ft_garbage_free_one(glo->garb.gbptr, map);
}

/*On a content-verified map : check if a path exist between P and E*/
void	ft_parsing_check_map_path(t_global *glo, char debug)
{
	t_coord		start;
	char		**map_cpy;
	long int	sum[2];

	sum[0] = 0;
	sum[1] = 0;
	map_cpy = fts_parsing_map_cpy(glo, glo->map, glo->map_h);
	ft_tools_elem_find(glo, glo->map, 'P', &start);
	fts_check_map_step(glo, map_cpy, start, sum);
	fts_parsing_map_free(glo, map_cpy, glo->map_h);
	if (*sum != 1 || sum[1] != ft_tools_elem_count(glo->map, 'C'))
		ft_parsing_map_error(&glo->garb.gbgroup, 6);
	if (debug)
		write(1, "  -valid path : ok\n", 19);
}
