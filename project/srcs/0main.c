/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:00:17 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 05:05:46 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_global	glo;

	if (ac != 2)
	{
		write(1, "Error\nExpect one argument only : the map name.\n", 47);
		return (1);
	}
	ft_init_pre_parsing_main(&glo);
	ft_parsing_main(&glo, av[1]);
	ft_init_post_parsing_main(&glo);
	ft_game_display(&glo);
	mlx_loop(glo.mlx);
	return (0);
}
