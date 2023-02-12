/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:05:21 by acardona          #+#    #+#             */
/*   Updated: 2023/02/12 04:48:40 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"

static int	ft_itoa_count(int n);

/*itoa without malloc for positiv int */
void	ft_itoa_mod(char str[12], int n)
{
	int		len;
	int		i ;

	len = ft_itoa_count(n);
	if (n < 0)
		return ;
	i = -1;
	while (len + ++i < 12)
		str[len + i] = 0;
	while (len > 0)
	{
		str[len-- - 1] = '0' + n % 10;
		n /= 10;
	}
}

static int	ft_itoa_count(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
