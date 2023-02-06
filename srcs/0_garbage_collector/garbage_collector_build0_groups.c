/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_build0_groups.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:40:14 by acardona          #+#    #+#             */
/*   Updated: 2023/02/05 22:02:44 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*generate a new garbage group  with on garbage for simple pointers to free() */
void	ft_garbage_group_init(t_garbage_resume *garb_lst)
{
	t_garb_del_arg	*args;

	args = malloc (sizeof (t_garb_del_arg));
	if (!args)
		exit(ERR_GARB);
	garb_lst->gbptr = malloc(sizeof(t_garbage));
	if (!garb_lst->gbptr)
	{
		free(args);
		exit(ERR_GARB);
	}
	args->arg1 = 0;
	args->arg2 = 0;
	args->arg3 = 0;
	garb_lst->gbptr->del_function = ft_garbage_del_gbptr;
	garb_lst->gbptr->first = 0;
	garb_lst->gbptr->parent_group = &(garb_lst->gbgroup);
	ft_garbage_group_add_garb(&(garb_lst->gbgroup), garb_lst->gbptr);
	ft_garbage_add(garb_lst->gbptr, args);
}

/*Generate the struct containing the bonus arguments necessary to free a ptr*/
t_garb_del_arg	*ft_garbage_del_arg_init(t_garbage_resume *garb_lst, void *arg1,
	void *arg2, void *arg3)
{
	t_garb_del_arg	*args;

	args = (t_garb_del_arg *)ft_my_malloc(garb_lst->gbptr,
			sizeof(t_garb_del_arg));
	args->arg1 = 0;
	args->arg2 = 0;
	args->arg3 = 0;
	if (arg1)
		args->arg1 = arg1;
	if (arg2)
		args->arg2 = arg2;
	if (arg3)
		args->arg3 = arg3;
	return (args);
}

/*add garb to the garbage list*/
void	ft_garbage_group_add_garb(t_garb_list **group, t_garbage *garb)
{
	t_garb_list	*elem;

	elem = malloc(sizeof(t_garb_list));
	if (!elem)
	{
		ft_garbage_free(garb, 0);
		ft_garbage_group_free(group, 1);
	}
	elem->content = (void *)garb;
	elem->next = *group;
	*group = elem;
	garb->parent_group = group;
}

/*free all garbages of the group related to the given garbage garb*/
int	ft_garbage_group_free(t_garb_list **group, int error_exit)
{
	t_garb_list	*elem;
	t_garb_list	*tmp;

	if (!*group)
		exit (error_exit);
	elem = (*group);
	while (elem)
	{
		tmp = elem->next;
		ft_garbage_free((t_garbage *)elem->content, 0);
		free(elem->content);
		free(elem);
		elem = tmp;
	}
	*group = 0;
	if (error_exit)
		exit(error_exit);
	return (0);
}
