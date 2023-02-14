/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_nl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:29:41 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:29:45 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"

static int	ft_itoa_count(int n);
static char	*ft_itoa_min(void);

char	*ft_itoa_nl(t_garbage *gb_ptr, int n)
{
	int		len;
	char	*str;
	int		neg;

	if (n == -2147483648)
		return (ft_itoa_min());
	len = ft_itoa_count(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	str = ft_my_malloc(gb_ptr, (len + neg + 2) * sizeof(char));
	if (neg)
	{
		n *= -1;
		str[0] = '-';
	}
	str[len + neg] = '\n';
	str[len + neg + 1] = 0;
	while (len > 0)
	{
		str[len-- + neg - 1] = '0' + n % 10;
		n /= 10;
	}
	return (str);
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

static char	*ft_itoa_min(void)
{
	char	*str;
	int		i;

	str = malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while ("-2147483648"[++i])
		str[i] = "-2147483648"[i];
	str[i] = '\0';
	return (str);
}
