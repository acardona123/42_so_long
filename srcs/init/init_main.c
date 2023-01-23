/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:00:04 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 02:57:22 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	fts_init_local_endian_init(t_global *glo, char debug)
{
	int	a;

	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		glo->local_endian = 1;
	else
		glo->local_endian = 0;
	if (debug)
	{
		write(1, "=> Local Endian :\n", 18);
		write(1, &("0\n\0 1\n"[(glo->local_endian * 4)]), 2);
	}
}

static void	fts_init_xvars_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> mlx init :\n", 14);
	glo->mlx = mlx_init();
	if (!glo->mlx)
		ft_garbage_group_free(&(glo->garb.gbgroup), 1);
	ft_garbage_add(glo->garb.gbxvar, glo->mlx);
	if (debug)
		write(1, " ok\n", 4);
}

static void	fts_init_win_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> mlx window init:\n", 20);
	glo->win = mlx_new_window(glo->mlx, WIDTH, HEIGHT, "Enjoy !");
	if (!glo->win)
		ft_garbage_group_free(&(glo->garb.gbgroup), 1);
	ft_garbage_add(glo->garb.gbwin, glo->win);
	if (debug)
		write(1, " ok\n", 4);
}

void	ft_init_main(t_global *glo, char debug)
{
	write(1, "==== Game initialisation ====\n\n", 32);
	fts_init_local_endian_init(glo, debug);
	ft_garbage_collector_init(glo, debug);
	fts_init_xvars_init(glo, debug);
	fts_init_win_init(glo, debug);
	ft_init_textures_init(glo, debug);
	/*
	initialiser les img qui serviront pour l'affichage (avec glo->map_size) 
	*/
}
