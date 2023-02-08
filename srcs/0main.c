/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:00:17 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 21:45:50 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_global	glo;

	ft_init_pre_parsing_main(&glo);
	ft_parsing_main(&glo, MAP_NAME);
	ft_init_post_parsing_main(&glo);

//  //Tests :
// 	mlx_put_image_to_window(glo.mlx , glo.win , glo.textures.exit->data.img, 0, 0);  // <=== Seg fault
// 	sleep(1);
// 	ft_tools_resize_img(&glo, &(glo.textures.exit->data), 256);
// 	sleep(1);

 	mlx_put_image_to_window(glo.mlx , glo.win , glo.background->img, 0, 0);
	
	mlx_loop(glo.mlx);
	//test(&glo);
	return (0);
}
