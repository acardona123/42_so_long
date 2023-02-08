/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_0main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:53:24 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 22:33:03 by acardona         ###   ########.fr       */
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
	frame1->frame = ft_tools_img_new(glo, glo->map_w * CHUNK_SIZE,
			glo->map_h * CHUNK_SIZE);
	frame2 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame2->frame = ft_tools_img_new(glo, glo->map_w * CHUNK_SIZE,
			glo->map_h * CHUNK_SIZE);
	frame1->next = frame2;
	frame1->next = frame1;
	ft_tools_elem_find(glo, glo->map, 'P', &frame1->co_player);
	glo->frames = frame1;
	glo->cam_co.x = frame1->co_player.x - WIN_WIDTH / 2;
	glo->cam_co.y = frame1->co_player.y - WIN_HEIGHT / 2;
	if (DEBUG)
		write(1, " ok\n", 4);
}

/*Init of the cam pos, window centered on player.*/
static void	fts_init_post_camera_init(t_global *glo)
{
	if (DEBUG)
		write(1, "=> camera init :\n", 17);
	glo->cam_lock = 1;
	glo->cam_co = (t_coord){0, 0};
	glo->cam_speed = 1;
	if (glo->map_w * CHUNK_SIZE <= WIN_WIDTH)
	{
		glo->cam_movable_x = 0;
		glo->cam_min_w = WIN_WIDTH / 2 - glo->map_w * CHUNK_SIZE / 2;
	}
	else
	{
		glo->cam_movable_x = 1;
		glo->cam_min_w = WIN_WIDTH - glo->map_w * CHUNK_SIZE;
	}
	if (glo->map_h * CHUNK_SIZE <= WIN_WIDTH)
	{
		glo->cam_movable_y = 0;
		glo->cam_min_h = WIN_HEIGHT / 2 - glo->map_w * CHUNK_SIZE / 2;
	}
	else
	{
		glo->cam_movable_y = 1;
		glo->cam_min_h = WIN_HEIGHT - glo->map_h * CHUNK_SIZE;
	}
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
	fts_init_post_frames_init(glo);
	fts_init_post_camera_init(glo);
	ft_init_post_hooks_init(glo);
	ft_init_post_background_init(glo);
	if (DEBUG)
		write(1, "- End of initialisation  -\n\n", 28);
}
