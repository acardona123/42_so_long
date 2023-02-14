/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:30:33 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:30:34 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"

t_list	*ft_lstnew(t_garbage *gbptr, void *content)
{
	t_list	*new;

	new = ft_my_malloc(gbptr, sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
