/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:02:07 by acardona          #+#    #+#             */
/*   Updated: 2023/02/19 16:28:54 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Close the game and free everything properly*/
void	ft_end_close(t_global *glo, char succes)
{
	t_data	*background;

	if (DEBUG)
		write(1, "\nProgram end, free all :\n", 25);
	if (!succes)
	{
		ft_garbage_group_free(&(glo->garb.gbgroup), 0);
		exit (0);
	}
	if (succes == 1)
	{
		glo->playing = 0;
		write (1, "\nVICTORY ! CONGRATULATIONS !\n", 29);
		background = ft_tools_img_new(glo, WIN_WIDTH, WIN_HEIGHT);
		ft_tools_img_draw_rec(background, 0X709999, (t_coord){0, 0},
			(t_coord){WIN_WIDTH, WIN_HEIGHT});
		mlx_put_image_to_window(glo->mlx, glo->win, background->img, 0, 0);
		mlx_put_image_to_window(glo->mlx, glo->win, glo->textures.victory->data
			.img, WIN_WIDTH / 2 - glo->textures.victory->img_width / 2,
			WIN_HEIGHT / 2 - glo->textures.victory->img_height / 2);
	}
	write(1, "\nThank you for playing, see you soon.\n\n", 39);
	write(1, "Textures : RPG Nature Tileset by Stealthix.\n", 44);
	glo->playing = 0;
}
