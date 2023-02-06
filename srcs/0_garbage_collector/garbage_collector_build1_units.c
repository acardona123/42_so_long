/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_build1_units.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:25 by acardona          #+#    #+#             */
/*   Updated: 2023/02/05 22:03:02 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*generate a new carbage (included in garbage group) with special free*/
t_garbage	*ft_garbage_special_init(t_garbage_resume *garb_lst,
		t_garb_del_arg *del_args,
		void (*del_function)(t_garb_del_arg *, void *))
{
	t_garbage	*garb;

	garb = malloc(sizeof(t_garbage));
	if (!garb)
	{
		if (garb_lst->gbgroup)
			ft_garbage_group_free(&(garb_lst->gbgroup), 1);
		exit(ERR_GARB);
	}
	garb->parent_group = &(garb_lst->gbgroup);
	garb->del_function = del_function;
	garb->del_arg = del_args;
	garb->first = 0;
	ft_garbage_group_add_garb(&garb_lst->gbgroup, garb);
	return (garb);
}

/*Free the content_taget pointer, remove it from garbage (return 1 if !found)*/
int	ft_garbage_free_one(t_garbage *garb, void *content_target)
{
	t_garb_list	*elem;
	t_garb_list	*tmp;

	if (!garb)
		return (1);
	elem = garb->first;
	if (elem && elem->content == content_target)
	{
		garb->first = elem->next;
		(*(garb->del_function))(garb->del_arg, elem->content);
		free(elem);
		return (0);
	}
	while (elem && elem->next && elem->next->content != content_target)
		elem = elem->next;
	if (elem && elem->next)
	{
		tmp = elem->next->next;
		(*(garb->del_function))(garb->del_arg, elem->next->content);
		free(elem->next);
		elem->next = tmp;
		return (0);
	}
	return (1);
}

/*free the given carbage content only. If error:free all garbages of garbgroup*/
int	ft_garbage_free(t_garbage *garb, int error_exit)
{
	t_garb_list	*pelem;
	t_garb_list	*pnext;

	if (!garb)
		return (1);
	if (error_exit && *(garb->parent_group))
		ft_garbage_group_free(garb->parent_group, error_exit);
	pelem = garb->first;
	while (pelem)
	{
		(*(garb->del_function))(garb->del_arg, pelem->content);
		pnext = pelem->next;
		free(pelem);
		pelem = pnext;
	}
	garb->first = 0;
	return (0);
}

/*Adds a new elem containing ptr (already malloced) to the the garbage lst*/
int	ft_garbage_add(t_garbage *garb, void *ptr)
{
	t_garb_list	*new_elem;

	new_elem = 0;
	if (!garb)
	{
		write(1, "Garbage collector uninitialized. Exit.\n", 39);
		exit(ERR_GARB);
	}
	if (!ptr)
		write(1, "/!\\ Added a NULL pinter to garbage. Normal ?\n", 45);
	new_elem = malloc(sizeof(t_garb_list));
	if (!new_elem)
	{
		(*(garb->del_function))(garb->del_arg, ptr);
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
