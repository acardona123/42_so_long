/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:30:38 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 02:46:01 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	fts_display_stat_sub(t_global *glo, char *str1, int n, t_coord co)
{
	char	str[12];
	char	*str2;

	*str = 0;
	ft_itoa_mod(str, n);
	str2 = ft_strjoin(glo->garb.gbptr, str1, str);
	mlx_string_put(glo->mlx, glo->win, co.x, co.y, 0xFFED6F, str2);
	ft_garbage_free_one(glo->garb.gbptr, str2);
}

/*Dipsplay player stats and game params on the screen*/
static void	fts_display_stat(t_global	*glo)
{
	mlx_put_image_to_window(glo->mlx, glo->win,
		glo->textures.stat_sign->data.img, 0, 0);
	if (glo->cpt_col)
		fts_display_stat_sub(glo, "Missing hearts : ", glo->cpt_col,
			(t_coord){2, 12});
	else
		mlx_string_put(glo->mlx, glo->win, 2, 12, 0xFFED6F, "Exit opened");
	fts_display_stat_sub(glo, "Mouvements : ", glo->cpt_move, (t_coord){2, 24});
	if (glo->cam_lock)
		mlx_string_put(glo->mlx, glo->win, 2, 36, 0xFFED6F, "Camera locked");
	else
		fts_display_stat_sub(glo, "Camera unlocked: v", glo->cam_speed,
			(t_coord){2, 36});
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
