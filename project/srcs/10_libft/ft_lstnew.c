/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_no_garbage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:54:58 by acardona          #+#    #+#             */
/*   Updated: 2023/02/01 21:38:23 by acardona         ###   ########.fr       */
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
