/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_0main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:53:24 by acardona          #+#    #+#             */
/*   Updated: 2023/02/07 01:49:15 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Initializes mlx and injects it into the global structure glo*/
static void	fts_init_post_xvars_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> mlx init :\n", 14);
	glo->mlx = mlx_init();
	if (!glo->mlx)
		ft_garbage_group_free(&(glo->garb.gbgroup), ERR_MLX);
	ft_garbage_add(glo->garb.gbptr, glo->mlx);
	ft_garbage_add(glo->garb.gbxvar, glo->mlx);
	if (debug)
		write(1, " ok\n", 4);
}

/*Initializes mlx_window and injects it into the global strucure glo*/
static void	fts_init_post_win_init(t_global *glo, char debug)
{
	if (debug)
		write(1, "=> mlx window init:\n", 20);
	glo->win = mlx_new_window(glo->mlx, WIDTH, HEIGHT, "Enjoy !");
	if (!glo->win)
		ft_garbage_group_free(&(glo->garb.gbgroup), ERR_MLX);
	ft_garbage_add(glo->garb.gbwin, glo->win);
	if (debug)
		write(1, " ok\n", 4);
}

/*initializes 2 img (map size) used later as canvas to displayed on the window*/
static void	fts_init_post_frames_init(t_global *glo, char debug)
{
	t_frames	*frame1;
	t_frames	*frame2;

	if (debug)
		write(1, "=> frames init :\n", 17);
	frame1 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame1->frame = ft_tools_img_new(glo, glo->map_w * CHUNK_SIZE,
			glo->map_h * CHUNK_SIZE);
	frame2 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame2->frame = ft_tools_img_new(glo, glo->map_w * CHUNK_SIZE,
			glo->map_h * CHUNK_SIZE);
	frame1->next = frame2;
	frame1->next = frame1;
	glo->frames = frame1;
	if (debug)
		write(1, " ok\n", 4);
}



/*Finish initialization of global structure after parsing(need map dimensions)*/
void	ft_init_post_parsing_main(t_global *glo, char debug)
{
	if (WIDTH * HEIGHT * CHUNK_SIZE < 1)
	{
		write(1, "Window or chunk dimensions incorrect.\n", 35);
		exit(1);
	}
	fts_init_post_xvars_init(glo, debug);
	fts_init_post_win_init(glo, debug);
	ft_init_post_textures_init(glo, debug);
	fts_init_post_frames_init(glo, debug);
	ft_init_post_hooks_init(glo, debug);
	ft_init_post_background_init(glo, debug);
	if (debug)
		write(1, "- End of initialisation  -\n\n", 28);
}
