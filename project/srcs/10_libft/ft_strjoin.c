/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:34:24 by acardona          #+#    #+#             */
/*   Updated: 2023/02/12 02:00:44 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft_so_long.h"

char	*ft_strjoin(t_garbage *gbptr, char const *s1, char const *s2)
{
	char	*s3;
	size_t	ltot;

	s3 = 0;
	ltot = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_my_malloc(gbptr, (ltot + 1) * sizeof(char));
	ft_strlcpy(s3, s1, ft_strlen(s1));
	ft_strlcpy(s3 + ft_strlen(s1), s2, ft_strlen(s2));
	s3[ltot] = 0;
	return (s3);
}
