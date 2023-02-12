/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_0init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:43:11 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 01:35:04 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*initialise garbage collector (/!\ order matter here, risk 2free)*/
void	ft_garbage_collector_init(t_global *glo)
{
	t_garb_del_arg	*arg_img;
	t_garb_del_arg	*arg_win;
	t_garb_del_arg	*arg_xvar;
	t_garb_del_arg	*arg_fd;

	if (DEBUG)
		write(1, "=> garbage collector init :\n", 28);
	ft_garbage_group_init(&(glo->garb));
	arg_img = ft_garbage_del_arg_init(&(glo->garb), glo, 0, 0);
	arg_win = ft_garbage_del_arg_init(&glo->garb, glo, 0, 0);
	arg_xvar = ft_garbage_del_arg_init(&glo->garb, 0, 0, 0);
	arg_fd = ft_garbage_del_arg_init(&glo->garb, 0, 0, 0);
	glo->garb.gbxvar = ft_garbage_special_init(&glo->garb, arg_xvar,
			&ft_garbage_del_gbxvar);
	glo->garb.gbwin = ft_garbage_special_init(&glo->garb, arg_win,
			&ft_garbage_del_gbwin);
	glo->garb.gbimg = ft_garbage_special_init(&glo->garb, arg_img,
			&ft_garbage_del_gbimg);
	glo->garb.gbfd = ft_garbage_special_init(&glo->garb, arg_fd,
			&ft_garbage_del_gbfd);
	if (DEBUG)
		write(1, " ok\n", 4);
}
