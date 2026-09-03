/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_extremum_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:36:09 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:27:57 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_tools_min_int(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	ft_tools_max_int(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
