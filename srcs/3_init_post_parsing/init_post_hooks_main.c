/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_hooks1 copy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:52:30 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:18:30 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*hook for clsing with the the cross*/
static int	fts_destroy_hook( t_global *glo)
{
	ft_end_close(glo, 0);
	return (0);
}

/*main hooks*/
void	ft_init_post_hooks_init_main(t_global *glo)
{
	if (DEBUG)
		write(1, "=> frames init :\n", 17);
	mlx_hook(glo->win, 2, 1L, &ft_post_hooks_key, glo);
	mlx_hook(glo->win, 17, 0, fts_destroy_hook, glo);
	if (DEBUG)
		write(1, " ok\n", 4);
}
