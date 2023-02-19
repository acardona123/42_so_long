/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:28:58 by acardona          #+#    #+#             */
/*   Updated: 2023/02/01 23:33:40 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Display an error msg and exit cleaning the garbage*/
void	ft_error_exit(t_garb_list **garb, int error_id, char *error_msg)
{
	write(1, "Error\n", 6);
	write(1, error_msg, ft_strlen(error_msg));
	write(1, "\n", 1);
	ft_garbage_group_free(garb, error_id);
}
