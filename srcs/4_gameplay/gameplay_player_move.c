/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_player_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:39:40 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 21:33:25 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Mooves the player to (x, y) chunk on he map (modifying the frames),NO DISPAY*/
static void	fts_game_player_move_to(t_global *glo, t_coord	p_co)
{
	char	*move;

	ft_tools_img_sub_cpy((t_img_cpy){glo->background, glo->frames->next->frame,
		glo->frames->next->co_player, glo->frames->next->co_player,
		CHUNK_SIZE, CHUNK_SIZE}); //gerer la taille du player au lieu de chunk_size?
	ft_tools_img_blend(glo->frames->next->frame, &glo->textures.player->data,
		p_co.x, p_co.y);
	glo->frames->next->co_player = p_co;
	glo->frames = glo->frames->next;
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

	pnext.x = glo->frames->co_player.x + step * dir.x;
	pnext.y = glo->frames->co_player.y + step * dir.y;
	if ((glo->map)[(pnext.y) / CHUNK_SIZE][(pnext.x) / CHUNK_SIZE] == '1')
		return (0);
	if ((glo->map)[(pnext.y) / CHUNK_SIZE][(pnext.x) / CHUNK_SIZE] == 'C')
	{
		(glo->map)[pnext.y / CHUNK_SIZE][pnext.x / CHUNK_SIZE] = 'c';
		ft_tools_img_blend(glo->background, &glo->textures.col_off->data,
			pnext.x, pnext.y);
		glo->cpt_col--;
		if (glo->cpt_col == 0)
			fts_game_open_exit(glo);
	}
	else if ((glo->map)[(pnext.y) / CHUNK_SIZE][(pnext.x) / CHUNK_SIZE] == 'E')
		if (glo->cpt_col == 0)
			ft_end_victory(glo);
	fts_game_player_move_to(glo, pnext);
	return (1);
}
