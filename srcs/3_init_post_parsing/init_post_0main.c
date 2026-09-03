/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_0main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:53:24 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 03:11:20 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Initializes mlx and injects it into the global structure glo*/
static void	fts_init_post_xvars_init(t_global *glo)
{
	if (DEBUG)
		write(1, "=> mlx init :\n", 14);
	glo->mlx = mlx_init();
	if (!glo->mlx)
		ft_garbage_group_free(&(glo->garb.gbgroup), ERR_MLX);
	ft_garbage_add(glo->garb.gbptr, glo->mlx);
	ft_garbage_add(glo->garb.gbxvar, glo->mlx);
	if (DEBUG)
		write(1, " ok\n", 4);
}

/*Initializes mlx_window and injects it into the global strucure glo*/
static void	fts_init_post_win_init(t_global *glo)
{
	if (DEBUG)
		write(1, "=> mlx window init:\n", 20);
	glo->win = mlx_new_window(glo->mlx, WIN_WIDTH, WIN_HEIGHT, "Enjoy !");
	if (!glo->win)
		ft_garbage_group_free(&(glo->garb.gbgroup), ERR_MLX);
	ft_garbage_add(glo->garb.gbwin, glo->win);
	if (DEBUG)
		write(1, " ok\n", 4);
}

/*initializes 2 img (map size) used later as canvas to displayed on the window*/
static void	fts_init_post_frames_init(t_global *glo)
{
	t_frames	*frame1;
	t_frames	*frame2;

	if (DEBUG)
		write(1, "=> frames init :\n", 17);
	frame1 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame1->frame = ft_tools_img_new(glo, glo->map_pw, glo->map_ph);
	ft_tools_img_cpy(glo->background, frame1->frame);
	frame2 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame2->frame = ft_tools_img_new(glo, glo->map_pw, glo->map_ph);
	ft_tools_img_cpy(glo->background, frame2->frame);
	frame1->next = frame2;
	frame2->next = frame1;
	ft_tools_elem_find(glo, glo->map, 'P', &frame1->co_player);
	frame1->co_player.x *= CHUNK_SIZE;
	frame1->co_player.y *= CHUNK_SIZE;
	frame2->co_player.x = frame1->co_player.x;
	frame2->co_player.y = frame1->co_player.y;
	ft_tools_img_blend(frame1->frame, &glo->textures.player->data,
		frame1->co_player.x, frame1->co_player.y);
	glo->frames = frame1;
	if (DEBUG)
		write(1, " ok\n", 4);
}

/*Init of the cam pos, window centered on player.*/
static void	fts_init_post_camera_init(t_global *glo)
{
	if (DEBUG)
		write(1, "=> camera init :\n", 17);
	glo->cam_lock = 1;
	glo->cam_speed = 1;
	glo->cam_co = (t_coord){0, 0};
	glo->cam_co_min = (t_coord){WIN_WIDTH / 2, WIN_HEIGHT / 2};
	glo->cam_co_max = (t_coord){glo->map_pw - WIN_WIDTH / 2,
		glo->map_ph - WIN_HEIGHT / 2};
	if (glo->map_pw <= WIN_WIDTH)
	{
		glo->cam_movable.x = 0;
		glo->cam_co.x = glo->map_pw / 2;
	}
	else
		glo->cam_movable.x = 1;
	if (glo->map_ph <= WIN_HEIGHT)
	{
		glo->cam_movable.y = 0;
		glo->cam_co.y = glo->map_ph / 2;
	}
	else
		glo->cam_movable.y = 1;
	ft_game_cam_reset(glo);
	if (DEBUG)
		write(1, " ok\n", 4);
}

/*Finish initialization of global structure after parsing(need map dimensions)*/
void	ft_init_post_parsing_main(t_global *glo)
{
	if (WIN_WIDTH * WIN_HEIGHT * CHUNK_SIZE < 1)
	{
		write(1, "Window or chunk dimensions incorrect.\n", 35);
		exit(1);
	}
	fts_init_post_xvars_init(glo);
	fts_init_post_win_init(glo);
	ft_init_post_textures_init(glo);
	ft_init_post_background_init(glo);
	fts_init_post_frames_init(glo);
	fts_init_post_camera_init(glo);
	ft_init_post_hooks_init_main(glo);
	if (DEBUG)
		write(1, "- End of initialisation  -\n\n", 28);
}
