/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:00:17 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 01:37:42 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	test(t_global *glo)
{
	write(1, "Closing game :\n", 15);
	printf("win p : %p\n", glo->win);//
	ft_garbage_free_one(glo->garb.gbwin, glo->win);//seg fault ici
	write(1, "ok\n", 3);//
	ft_garbage_group_free(&(glo->garb.gbgroup), 0);
	printf("Tout va bien\n");
	exit(0);
}


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
