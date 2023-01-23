/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_init_pre_parsing.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:00:04 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 15:55:54 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Calculates local endian and injects it into the global strucure glo*/
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

/*Security : calculate endian and set global structure values to 0*/
static void	fts_init_global_reset(t_global *glo, char debug)
{
	fts_init_local_endian_init(glo, debug);
	glo->garb.gbgroup = 0;
	glo->garb.gbimg = 0;
	glo->garb.gbptr = 0;
	glo->garb.gbwin = 0;
	glo->garb.gbxvar = 0;
	glo->mlx = 0;
	glo->win = 0;
	glo->textures = 0;
	glo->frames = 0;
	glo->move_cpt = 0;
}

/*Initialize the global strucure glo before map parsing ...*/
void	ft_init_main_init_pre_parsing(t_global *glo, char debug)
{
	write(1, "\n===== Initialisation =====\n", 28);
	fts_init_global_reset(glo, debug);
	ft_garbage_collector_init(glo, debug);
}
