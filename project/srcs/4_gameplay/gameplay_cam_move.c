/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_cam_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:33:22 by acardona          #+#    #+#             */
/*   Updated: 2023/02/11 22:23:25 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Center the player int the screen */
void	ft_game_cam_reset(t_global *glo)
{
	if (glo->cam_movable.x)
	{
		if (glo->frames->co_player.x < glo->cam_co_min.x)
			glo->cam_co.x = glo->cam_co_min.x;
		else if (glo->frames->co_player.x > glo->cam_co_max.x)
			glo->cam_co.x = glo->cam_co_max.x;
		else
			glo->cam_co.x = glo->frames->co_player.x;
	}
	if (glo->cam_movable.y)
	{
		if (glo->frames->co_player.y < glo->cam_co_min.y)
			glo->cam_co.y = glo->cam_co_min.y;
		else if (glo->frames->co_player.y > glo->cam_co_max.y)
			glo->cam_co.y = glo->cam_co_max.y;
		else
			glo->cam_co.y = glo->frames->co_player.y;
	}
}

/*Relative mvt of the cam*/
/*
void	ft_game_cam_move(t_global *glo, int step, t_coord dir)
{
	if (dir.x && glo->cam_movable.x)
	{
		glo->cam_co.x += step * glo->cam_speed * dir.x;
		if (glo->cam_co.x < glo->cam_co_min.x)
			glo->cam_co.x = glo->cam_co_min.x;
		else if (glo->cam_co.x > glo->cam_co_max.x)
			glo->cam_co.x = glo->cam_co_max.x;
	}
	if (dir.y && glo->cam_movable.y)
	{
		glo->cam_co.y += step * glo->cam_speed * dir.y;
		if (glo->cam_co.y < glo->cam_co_min.y)
			glo->cam_co.y = glo->cam_co_min.y;
		else if (glo->cam_co.y > glo->cam_co_max.y)
			glo->cam_co.y = glo->cam_co_max.y;
	}		
}
*/

/*Relative mvt of the cam. Check=0 if cam move linked to player */
void	ft_game_cam_move(t_global *glo, int step, t_coord dir)
{
	if (dir.x && glo->cam_movable.x)
	{
		glo->cam_co.x += step * glo->cam_speed * dir.x;
		if (glo->cam_co.x < glo->cam_co_min.x)
			glo->cam_co.x = glo->cam_co_min.x;
		else if (glo->cam_co.x > glo->cam_co_max.x)
			glo->cam_co.x = glo->cam_co_max.x;
	}
	if (dir.y && glo->cam_movable.y)
	{
		glo->cam_co.y += step * glo->cam_speed * dir.y;
		if (glo->cam_co.y < glo->cam_co_min.y)
			glo->cam_co.y = glo->cam_co_min.y;
		else if (glo->cam_co.y > glo->cam_co_max.y)
			glo->cam_co.y = glo->cam_co_max.y;
	}
}
