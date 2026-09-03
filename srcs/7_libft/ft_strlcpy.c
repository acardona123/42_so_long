/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:30:56 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:31:22 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i_char;
	size_t	i_int;
	int		size_int;

	size_int = sizeof(int);
	i_char = ft_strlen(src) % size_int;
	i_int = ft_strlen(src) / size_int;
	while (i_char > 0 && size > 0)
	{
		if (*src)
			*dst = *src;
		src++;
		dst++;
		i_char--;
		size--;
	}
	while (i_int && size > 0)
	{
		if (*src)
			*((int *)dst) = *((int *)src);
		src = (char *)src + size_int;
		dst = (char *)dst + size_int;
		i_int--;
		size -= size_int;
	}
}
