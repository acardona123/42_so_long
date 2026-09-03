/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_int_in_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:00:36 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:06:45 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*searches n in a tab of int terminated by null*/
int	ft_n_in_tab(int	*tab, int n)
{
	while (*tab)
	{
		if (*tab == n)
			return (1);
		tab++;
	}
	return (0);
}
