/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:34:24 by acardona          #+#    #+#             */
/*   Updated: 2023/02/01 22:07:31 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	ltot;

	ltot = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((ltot + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s3 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s3);
}