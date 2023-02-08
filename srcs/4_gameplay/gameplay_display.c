/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:30:38 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 23:10:56 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Determine if,  for a player position given, the map will fillthe screen */
static int	ft_gameplay_win_full(t_global *glo)
{
	(void)glo;
	/*to do mais vraiment necessaire que si map plus petite que fenetre, dans ce ca on pourrait fixer la map et bouger le player*/
	return (1);
}

/*Dipsplay player stats on the screen*/
static void	fts_display_stat(t_global	*glo)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_itoa_nl(glo->garb.gbptr, glo->cpt_move);
	if (glo->cam_lock)
		str3 = ft_strjoin(glo->garb.gbptr, "Camera locked\nMouvement count : ",
				str1);
	else
		str3 = ft_strjoin(glo->garb.gbptr,
				"Camera unlocked\nMouvement count : ", str1);
	ft_garbage_free_one(glo->garb.gbptr, str1);
	if (glo->cpt_col)
	{
		str1 = ft_strjoin(glo->garb.gbptr, str3, "Collectibles remaining : ");
		ft_garbage_free_one(glo->garb.gbptr, str3);
		str2 = ft_itoa_nl(glo->garb.gbptr, glo->cpt_col);
		str3 = ft_strjoin(glo->garb.gbptr, str1, str2);
		ft_garbage_free_one(glo->garb.gbptr, str2);
	}
	else
	{
		str2 = ft_strjoin(glo->garb.gbptr, str3, "Exit unlocked");
		ft_garbage_free_one(glo->garb.gbptr, str3);
		str3 = str2;
	}
	mlx_string_put(glo->mlx, glo->win, 0, 0, 0, str3);
	ft_garbage_free_one(glo->garb.gbptr, str3);
}

void	ft_game_display(t_global *glo)
{
	ft_gameplay_win_full(glo);
	if (0)//!ft_gameplay_win_full(glo)
		mlx_clear_window(glo->mlx, glo->win);
	mlx_put_image_to_window(glo->mlx, glo->win, glo->frames->frame->img,
		glo->cam_co.x, glo->cam_co.y);
		fts_display_stat(glo);
	/*To do*/

	
}
