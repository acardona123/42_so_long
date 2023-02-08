/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:24:01 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 03:25:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

#include <stdio.h>

/*transfers the elements of the list to the map (table of strings)*/
static void	fts_parse_lst_to_map(t_global *glo, t_list **lst)
{
	size_t	i;
	t_list	*elem;
	t_list	*tmp;

	glo->map = ft_my_malloc(glo->garb.gbptr, ((glo->map_h) + 1) * sizeof(char *));
	elem = *lst;
	i = 0;
	while (elem)
	{
		(glo->map)[i] = elem->content;
		tmp = elem->next;
		ft_garbage_free_one(glo->garb.gbptr, elem);
		elem = tmp;
		i++;
	}
	(glo->map)[i] = 0;
}

/*Convert a mapfile into a string and set the number of lines in glostruct*/
void	ft_parsing_file_to_map(t_global *glo, int *fd)
{
	t_list	*lst;
	t_list	*elem;
	char	*line;

	line = get_next_line(*fd);
	lst = 0;
	while (line)
	{
		ft_garbage_add(glo->garb.gbptr, line);
		elem = ft_lstnew_no_garbage(line);
		if (!elem)
		{
			ft_error_exit(&glo->garb.gbgroup, 1, "Malloc fail.");
		}
		ft_garbage_add(glo->garb.gbptr, elem);
		ft_lstadd_back(&lst, elem);
		line = get_next_line(*fd);
	}
	ft_garbage_free_one(glo->garb.gbfd, fd);
	glo->map_h = ft_lstsize(lst);
	fts_parse_lst_to_map(glo, &lst);
	if (DEBUG)
		write(1, "  -conversion file to map : ok\n", 31);
}
