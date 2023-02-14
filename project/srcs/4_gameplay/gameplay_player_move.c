/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_player_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:39:40 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 02:54:37 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Mooves the player to (x, y) chunk on he map (modifying the frames),NO DISPAY*/
static void	fts_game_player_move_to(t_global *glo, t_coord	p_co)
{
	char		*move;

	glo->frames = glo->frames->next;
	ft_tools_img_sub_cpy((t_img_cpy){glo->background, glo->frames->frame,
		glo->frames->co_player, glo->frames->co_player, CHUNK_SIZE,
		CHUNK_SIZE}); //gerer la taille du player au lieu de chunk_size?
	ft_tools_img_blend(glo->frames->frame, &glo->textures.player->data,
		p_co.x, p_co.y);
	glo->frames->co_player.x = p_co.x;
	glo->frames->co_player.y = p_co.y;
	if (glo->frames->next->co_player.x / CHUNK_SIZE
		!= glo->frames->co_player.x / CHUNK_SIZE
		|| glo->frames->next->co_player.y / CHUNK_SIZE
		!= glo->frames->co_player.y / CHUNK_SIZE)
	{
		glo->cpt_move++;
		if (MOUV_ON_TERM)
		{
			move = ft_itoa_nl(glo->garb.gbptr, glo->cpt_move);
			write(1, move, ft_strlen(move));
			ft_garbage_free_one(glo->garb.gbptr, move);
		}
	}
}

/*Define the cam direction according to player dir and position*/
static t_coord	fts_game_player_cam_lim(t_global *glo, t_coord dir_player)
{
	t_coord	dir_cam;

	if ((dir_player.x > 0 && glo->frames->co_player.x < glo->cam_co_min.x)
		|| (dir_player.x < 0 && glo->frames->co_player.x > glo->cam_co_max.x))
		dir_cam.x = 0;
	else
		dir_cam.x = dir_player.x;
	if ((dir_player.y > 0 && glo->frames->co_player.y < glo->cam_co_min.y)
		|| (dir_player.y < 0 && glo->frames->co_player.y > glo->cam_co_max.y))
		dir_cam.y = 0;
	else
		dir_cam.y = dir_player.y;
	return (dir_cam);
}

/*A revoir pour verifier la collision du joueur avec un autre element*/

int	ft_game_player_move(t_global *glo, int step, t_coord dir)
{
	t_coord	pnext;
	int		collec;

	pnext.x = glo->frames->co_player.x + step * dir.x;
	pnext.y = glo->frames->co_player.y + step * dir.y;
	collec = 0;
	if ((glo->map)[(pnext.y) / CHUNK_SIZE][(pnext.x) / CHUNK_SIZE] == '1')
		return (0);
	if ((glo->map)[(pnext.y) / CHUNK_SIZE][(pnext.x) / CHUNK_SIZE] == 'C')
	{
		(glo->map)[pnext.y / CHUNK_SIZE][pnext.x / CHUNK_SIZE] = 'c';
		ft_tools_img_blend(glo->background, &glo->textures.col_off->data,
			pnext.x, pnext.y);
		collec = 1;
		if (--glo->cpt_col == 0)
			fts_game_open_exit(glo);
	}
	fts_game_player_move_to(glo, pnext);
	if (collec)
		ft_tools_img_blend(glo->frames->next->frame,
			&glo->textures.col_off->data, pnext.x, pnext.y);
	if (glo->cam_lock)
		ft_game_cam_move(glo, step, fts_game_player_cam_lim(glo, dir));
	return (1);
}
