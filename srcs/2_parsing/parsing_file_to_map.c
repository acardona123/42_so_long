/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:24:01 by acardona          #+#    #+#             */
/*   Updated: 2023/02/02 21:13:10 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*transfers the elements of the list to the map (table of strings)*/
static void	fts_parse_lst_to_tab(t_global *glo, char **map, t_list **lst)
{
	size_t	i;
	t_list	*elem;
	t_list	*tmp;

	map = malloc((glo->map_h) * sizeof(char *) + 1);
	if (!map)
	{
		ft_lstclear(lst);
		ft_garbage_group_free(&glo->garb.gbgroup, 1);
	}
	ft_garbage_add(glo->garb.gbptr, map);
	elem = *lst;
	i = 0;
	while (elem)
	{
		map[i] = (char *)(elem->content);
		i++;
		tmp = elem->next;
		free(tmp);
		elem = tmp;
	}
	map[i] = 0;
}

/*Convert a mapfile into a string and set the number of lines in glostruct*/
void	ft_parsing_file_to_map(t_global *glo, int *fd, char **map, char debug)
{
	t_list	*lst;
	t_list	*elem;
	char	*line;

	line = get_next_line(*fd);
	lst = 0;
	while (line)
	{
		ft_garbage_add(glo->garb.gbptr, line);
		elem = ft_lstnew(line);
		if (!elem)
		{
			ft_lstclear(&lst);
			ft_error_exit(&glo->garb.gbgroup, 1, "Malloc fail.");
		}
		ft_lstadd_back(&lst, elem);
		line = get_next_line(*fd);
	}
	ft_garbage_free_one(glo->garb.gbfd, fd);
	glo->map_h = ft_lstsize(lst);
	fts_parse_lst_to_tab(glo, map, &lst);
	if (debug)
		write(1, "  -conversion file to map : ok\n", 31);
}
