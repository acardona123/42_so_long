/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_free_ftn.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:28:00 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 02:57:15 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*del for gbptr : simle ptr to free with free()*/
void	ft_garbage_del_gbptr(t_garb_del_arg *args, void *to_del)
{
	(void)args;
	free(to_del);
}

/*del for gbxvar : pointer allocated with mlx_init()*/
void	ft_garbage_del_gbxvar(t_garb_del_arg *args, void *to_del)
{
	(void)args;
	mlx_destroy_display(to_del);
}

/*del for gbimg : pointer allocated with mlx_new_image*/
void	ft_garbage_del_gbimg(t_garb_del_arg *args, void *to_del)
{
	mlx_destroy_image(args->arg1, to_del);
}

/*del for gbwin : pointer allocated with mlx_new_window*/
void	ft_garbage_del_gbwin(t_garb_del_arg *args, void *to_del)
{
	mlx_destroy_window(args->arg1, to_del);
}
