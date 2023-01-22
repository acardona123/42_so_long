/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_0_groups.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:40:14 by acardona          #+#    #+#             */
/*   Updated: 2023/01/22 01:51:49 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*add garb to the garbage list*/
void	ft_garbage_group_add_garb(t_list **group, t_garbage *garb)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
	{
		ft_garbage_free(garb, 0);
		ft_garbage_group_free(group, 1);
	}
	elem->content = (void *)garb;
	elem->next = *group;
	*group = elem;
}

/*free all garbages of the group related to the given garbage garb*/
int	ft_garbage_group_free(t_list **group, int error_exit)
{
	t_list	*elem;
	t_list	*tmp;

	if (!*group)
		exit (error_exit);
	elem = *group;
	while (elem)
	{
		tmp = elem->next;
		ft_garbage_free((t_garbage *)elem->content, 0);
		free(elem->content);
		free(elem);
		elem = tmp;
	}
	if (error_exit)
		exit(error_exit);
	return (1);
}
