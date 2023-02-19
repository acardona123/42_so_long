/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:30:22 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:30:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*pelem;
	t_list	*pnext;

	if (lst)
	{
		pelem = *lst;
		while (pelem)
		{
			free(pelem->content);
			pnext = pelem->next;
			free(pelem);
			pelem = pnext;
		}
		*lst = NULL;
	}
}
