/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:52:30 by acardona          #+#    #+#             */
/*   Updated: 2023/02/12 04:48:23 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*hooks related to cam settings*/
static void	fts_key_hook_cam_set(int key_code, t_global *glo)
{
	if (key_code == XK_c && (glo->cam_movable.x || glo->cam_movable.y))
	{
		if (glo->cam_lock == 1)
			glo->cam_lock = 0;
		else
		{
			glo->cam_lock = 1;
			ft_game_cam_reset(glo);
		}
	}
	else if (key_code == XK_plus)
		glo->cam_speed = (glo->cam_speed + 1) % MAX_CAM_SPEED;
	else if (key_code == XK_minus && glo->cam_speed > 0)
		(glo->cam_speed)--;
	else if (key_code == XK_Home)
		ft_game_cam_reset(glo);
}

/*hooks related to player movement, move cam if cam_lock*/
static void	fts_key_hook_player(int key_code, t_global *glo, int step)
{
	t_coord	dir;

	dir = (t_coord){0, 0};
	if (key_code == XK_w || key_code == XK_Up)
		dir.y -= 1;
	else if (key_code == XK_s || key_code == XK_Down)
		dir.y += 1;
	else if (key_code == XK_a || key_code == XK_Left)
		dir.x -= 1;
	else if (key_code == XK_d || key_code == XK_Right)
		dir.x += 1;
	ft_game_player_move(glo, step, dir);
}

/*if !cam_lock : hooks related to cam movement only*/
static void	fts_key_hook_cam_move(int key_code, t_global *glo, int step)
{
	t_coord	dir;

	dir = (t_coord){0, 0};
	if (key_code == XK_Up)
		dir.y -= 1;
	else if (key_code == XK_Down)
		dir.y += 1;
	else if (key_code == XK_Left)
		dir.x -= 1;
	else if (key_code == XK_Right)
		dir.x += 1;
	ft_game_cam_move(glo, step, dir);
}

/*Init keys hooks*/
static int	fts_key_hook(int key_code, t_global *glo)
{
	int	step;

	step = CHUNK_SIZE;//ici future step variable selon fps
	if (key_code == XK_Escape)
		ft_end_close(glo, 0);
	else if (glo->playing)
	{
		if (key_code == XK_Home || key_code == XK_c || key_code == XK_plus
			|| key_code == XK_minus)
			fts_key_hook_cam_set(key_code, glo);
		else if (glo->cam_lock || key_code == XK_w || key_code == XK_s
			|| key_code == XK_a || key_code == XK_d)
			fts_key_hook_player(key_code, glo, step);
		else if (key_code == XK_Up || key_code == XK_Down || key_code == XK_Left
			|| key_code == XK_Right)
			fts_key_hook_cam_move(key_code, glo, step);
		ft_game_display(glo);
		if ((glo->map)[(glo->frames->co_player.y) / CHUNK_SIZE]
			[(glo->frames->co_player.x) / CHUNK_SIZE] == 'E'
			&& glo->cpt_col == 0)
			ft_end_close(glo, 1);
	}
	return (0);
}

void	ft_init_post_hooks_init(t_global *glo)
{
	if (DEBUG)
		write(1, "=> frames init :\n", 17);
	mlx_key_hook(glo->win, &fts_key_hook, glo);
	//mlx_mouse_hook(glo->win, &fts_mouse_hook, &glo);
	if (DEBUG)
		write(1, " ok\n", 4);
}
