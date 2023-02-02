/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:35:00 by acardona          #+#    #+#             */
/*   Updated: 2023/02/01 22:14:59 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_SO_LONG_H
# define LIBFT_SO_LONG_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "garbage.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new1);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

#endif