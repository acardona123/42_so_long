/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:35:00 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 03:30:58 by acardona         ###   ########.fr       */
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
t_list	*ft_lstnew_no_garbage(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new1);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
char	*ft_strjoin(t_garbage *gbptr, char const *s1, char const *s2);
char	*ft_itoa_nl(t_garbage *gb_ptr, int n);

#endif