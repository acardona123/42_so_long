/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_my_malloc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:15:53 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 16:17:39 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Act as malloc but saves malloced pointers into garbage collector*/
void	*ft_my_malloc(t_garbage *garb, size_t size)
{
	void	*rtn;

	if (!garb)
		return (0);
	rtn = malloc(size);
	if (!rtn)
		ft_garbage_free(garb, 1);
	ft_garbage_add(garb, rtn);
	return (rtn);
}
