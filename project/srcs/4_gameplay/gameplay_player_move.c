/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_player_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:39:40 by acardona          #+#    #+#             */
/*   Updated: 2023/02/12 01:21:22 by acardona         ###   ########.fr       */
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
		move = ft_itoa_nl(glo->garb.gbptr, glo->cpt_move);
		write(1, move, ft_strlen(move));
	}
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
		glo->cpt_col--;
		if (glo->cpt_col == 0)
			fts_game_open_exit(glo);
	}
	fts_game_player_move_to(glo, pnext);
	if (collec)
		ft_tools_img_blend(glo->frames->next->frame,
			&glo->textures.col_off->data, pnext.x, pnext.y);
	if (glo->cam_lock)
	{
		if ((dir.x > 0 && glo->frames->co_player.x < glo->cam_co_min.x)
			|| (dir.x < 0 && glo->frames->co_player.x > glo->cam_co_max.x))
			dir.x = 0;
		if ((dir.y > 0 && glo->frames->co_player.y < glo->cam_co_min.y)
			|| (dir.y < 0 && glo->frames->co_player.y > glo->cam_co_max.y))
			dir.y = 0;
		ft_game_cam_move(glo, step, dir);
	}
	return (1);
}
