/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:52:30 by acardona          #+#    #+#             */
/*   Updated: 2023/02/07 03:05:04 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Init keys hooks*/
static int	fts_key_hook(int key_code, t_global *glo)
{
	if (key_code == XK_w || key_code == XK_Up)
		printf("w\n");
	else if (key_code == XK_s || key_code == XK_Down)
		printf("s\n");
	else if (key_code == XK_a || key_code == XK_Left)
		printf("a\n");
	else if (key_code == XK_d || key_code == XK_Right)
		printf("d\n");
	else if (key_code == XK_Escape)
	{
		write(1, "Closing game.\n", 14);
		printf("win p : %p\n", glo->win);//
		ft_garbage_free_one(glo->garb.gbwin, glo->win);//seg fault ici
		write(1, "ok\n", 3);//
		ft_garbage_group_free(&(glo->garb.gbgroup), 0);
		exit(0);
	}
	else//
		printf("%d\n", key_code);//
	return (0);
}

void	ft_init_post_hooks_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> frames init :\n", 17);
	mlx_key_hook(glo->win, &fts_key_hook, &glo); 
	//mlx_mouse_hook(glo->win, &fts_mouse_hook, &glo);
	if (debug)
		write(1, " ok\n", 4);
}
