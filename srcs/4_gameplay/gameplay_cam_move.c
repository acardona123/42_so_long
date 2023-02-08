/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_cam_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:33:22 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 23:03:39 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Center the player int the screen */
void	ft_game_cam_reset(t_global *glo)
{
	if (glo->cam_movable_x)
		glo->cam_co.x = ft_tools_max_int(glo->cam_min_w,
				WIN_WIDTH / 2 - glo->frames->co_player.x);
	else
		glo->cam_co.x = glo->cam_min_w;
	if (glo->cam_movable_y)
		glo->cam_co.y = ft_tools_max_int(glo->cam_min_h,
				WIN_HEIGHT / 2 - glo->frames->co_player.y);
	else
		glo->cam_co.y = glo->cam_min_h;
}

/*Relative mvt of the cam*/
void	ft_game_cam_move(t_global *glo, int step, t_coord dir)
{
	if (dir.x && glo->cam_movable_x)
	{
		glo->cam_co.x += step * glo->cam_speed * dir.x;
		if (glo->cam_co.x > 0)
			glo->cam_co.x = 0;
		else if (glo->cam_co.x < glo->cam_min_w)
			glo->cam_co.x = glo->cam_min_w;
	}
	if (dir.y && glo->cam_movable_y)
	{
		glo->cam_co.y += step * glo->cam_speed * dir.y;
		if (glo->cam_co.y > 0)
			glo->cam_co.y = 0;
		else if (glo->cam_co.y < glo->cam_min_h)
			glo->cam_co.y = glo->cam_min_h;
	}		
}
