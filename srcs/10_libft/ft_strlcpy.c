/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:38:48 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 03:35:55 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"
#include <X11/Xutil.h>
#include <stddef.h>
/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
*/
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
