/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:30:38 by acardona          #+#    #+#             */
/*   Updated: 2023/02/12 05:19:54 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Dipsplay player stats and game params on the screen*/
static void	fts_display_stat(t_global	*glo)
{
	char	str[12];
	char	*str1;

	*str = 0;
	mlx_put_image_to_window(glo->mlx, glo->win,
		glo->textures.stat_sign->data.img, 0, 0);
	if (glo->cpt_col)
	{
		ft_itoa_mod(str, glo->cpt_col);
		str1 = ft_strjoin(glo->garb.gbptr, "Missing hearts : ", str);
		mlx_string_put(glo->mlx, glo->win, 2, 12, 0xFFED6F, str1);
		ft_garbage_free_one(glo->garb.gbptr, str1);
	}
	else
		mlx_string_put(glo->mlx, glo->win, 2, 12, 0xFFED6F, "Exit opened");
	ft_itoa_mod(str, glo->cpt_move);
	str1 = ft_strjoin(glo->garb.gbptr, "Mouvements : ", str);
	mlx_string_put(glo->mlx, glo->win, 2, 24, 0xFFED6F, str1);
	ft_garbage_free_one(glo->garb.gbptr, str1);
	if (glo->cam_lock)
		mlx_string_put(glo->mlx, glo->win, 2, 36, 0xFFED6F, "Camera locked");
	else
		mlx_string_put(glo->mlx, glo->win, 2, 36, 0xFFED6F, "Camera unlocked");
}

/*Only displays mouvement count on the screen*/
static void	fts_display_minimal_stat(t_global *glo)
{
	char	str[12];

	*str = 0;
	ft_itoa_mod(str, glo->cpt_move);
	mlx_string_put(glo->mlx, glo->win, 2, 12, 0xFFED6F, str);
}

/*Display the frame and the stats (both previously generated)*/
void	ft_game_display(t_global *glo)
{
	if (!glo->cam_movable.y)
		mlx_clear_window(glo->mlx, glo->win);
	mlx_put_image_to_window(glo->mlx, glo->win, glo->frames->frame->img,
		WIN_WIDTH / 2 - glo->cam_co.x, WIN_HEIGHT / 2 - glo->cam_co.y);
	if (WIN_WIDTH > 130)
		fts_display_stat(glo);
	else
		fts_display_minimal_stat(glo);

}
