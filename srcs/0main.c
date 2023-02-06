/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:00:17 by acardona          #+#    #+#             */
/*   Updated: 2023/02/06 03:29:13 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_global	glo;
	int			debug;

	debug = 1;
	ft_init_pre_parsing_main(&glo, debug);
	ft_parsing_main(&glo, MAP_NAME, debug);
	ft_init_post_parsing_main(&glo, debug);
	
 //Tests :
	printf("%p\n", &glo.textures.exit->data);
	mlx_put_image_to_window(glo.mlx , glo.win , &(glo.textures.exit->data), 0, 0);
	mlx_loop(glo.mlx);
//

	ft_garbage_group_free(&glo.garb.gbgroup, 0);
	return (0);
}
