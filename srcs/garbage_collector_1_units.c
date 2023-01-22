/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_1_units.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:25 by acardona          #+#    #+#             */
/*   Updated: 2023/01/22 01:44:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*generate a new carbage (included in garbage group). del free its content*/
t_garbage	*ft_garbage_init(t_list	**group, void (*del)(void *))
{
	t_garbage	*garb;

	garb = malloc(sizeof(t_garbage));
	if (!garb)
	{
		if (group)
			ft_garbage_group_free(group, 1);
		exit(1);
	}
	garb->del_function = del;
	garb->first = 0;
	garb->parent_group = group;
	ft_garbage_group_add_garb(group, garb);
	return (garb);
}

/*Free the content_taget pointer, remove it from garbage (return 1 if !found)*/
int	ft_garbage_free_one(t_garbage *garb, void *content_target)
{
	t_list	*elem;
	t_list	*tmp;

	if (!garb)
		return (1);
	elem = garb->first;
	if (elem && elem->content == content_target)
	{
		garb->first = elem->next;
		(*(garb->del_function))(elem->content);
		free(elem);
		return (0);
	}
	while (elem && elem->next && elem->next->content != content_target)
		elem = elem->next;
	if (elem && elem->next)
	{
		tmp = elem->next->next;
		(*(garb->del_function))(elem->next->content);
		free(elem->next);
		elem->next = tmp;
		return (0);
	}
	return (1);
}

/*free entirely the carbage. If error free all garbages of parent_group*/
int	ft_garbage_free(t_garbage *garb, int error_exit)
{
	t_list	*pelem;
	t_list	*pnext;

	if (!garb)
		return (1);
	if (error_exit && garb->parent_group)
		ft_garbage_group_free(garb->parent_group, error_exit);
	pelem = garb->first;
	while (pelem)
	{
		(*(garb->del_function))(pelem->content);
		pnext = pelem->next;
		free(pelem);
		pelem = pnext;
	}
	garb->first = NULL;
	return (0);
}

/*Adds a new elem containing ptr (already malloced) to the the garbage lst*/
int	ft_garbage_add(t_garbage *garb, void *ptr)
{
	t_list	*new_elem;

	new_elem = 0;
	if (!garb)
	{
		write(1, "Garbage collector uninitialized. Exit.\n", 39);
		exit(1);
	}
	if (!ptr)
		ft_garbage_free(garb, 1);
	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		(*(garb->del_function))(ptr);
		ft_garbage_free(garb, 1);
	}
	new_elem->content = ptr;
	if (garb->first)
		new_elem->next = garb->first;
	else
		new_elem->next = 0;
	garb->first = new_elem;
	return (0);
}

/*Act as malloc but saves malloced pointers into garbage collector*/
int	ft_my_malloc(t_garbage *garb, void **dst, size_t size)
{
	if (!garb || !dst)
		return (1);
	if (ft_garbage_free_one(garb, *dst) == 0)
		write(1, "\e[31;1m/!\\ Realocation of malloced pointer.\e[0m\n", 48);
	*dst = malloc(size);
	if (!dst)
		ft_garbage_free(garb, 1);
	ft_garbage_add(garb, *dst);
	return (0);
}
