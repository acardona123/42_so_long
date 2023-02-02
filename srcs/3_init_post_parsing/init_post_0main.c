/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_post_0main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:53:24 by acardona          #+#    #+#             */
/*   Updated: 2023/02/02 21:07:50 by acardona         ###   ########.fr       */
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
		ft_garbage_group_free(&(glo->garb.gbgroup), 1);
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
		ft_garbage_group_free(&(glo->garb.gbgroup), 1);
	ft_garbage_add(glo->garb.gbwin, glo->win);
	if (debug)
		write(1, " ok\n", 4);
}

/*initializes 2 img (map size) used later as canvas to displayed on the window*/
static void	fts_init_post_frames_init(t_global *glo, char debug)
{
	t_frames	*frame1;
	t_frames	*frame2;

	(void)debug;
	frame1 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame2 = (t_frames *)ft_my_malloc(glo->garb.gbptr, sizeof(t_frames));
	frame1->frame.img = mlx_new_image(glo->mlx, glo->map_w * glo->chunk_size,
			glo->map_h * glo->chunk_size);
	if (!(frame1->frame.img))
		ft_garbage_group_free(&(glo->garb.gbgroup), 1);
	ft_garbage_add(glo->garb.gbimg, frame1->frame.img);
	frame2->frame.img = mlx_new_image(glo->mlx, glo->map_w * glo->chunk_size,
			glo->map_h * glo->chunk_size);
	if (!(frame2->frame.img))
		ft_garbage_group_free(&(glo->garb.gbgroup), 1);
	ft_garbage_add(glo->garb.gbimg, frame2->frame.img);
	frame1->frame.addr = mlx_get_data_addr(frame1->frame.img,
			&(frame1->frame.bits_per_pixel),
			&(frame1->frame.line_length), &(frame1->frame.endian));
	frame2->frame.addr = mlx_get_data_addr(frame2->frame.img,
			&(frame2->frame.bits_per_pixel),
			&(frame2->frame.line_length), &(frame2->frame.endian));
	frame1->next = frame2;
	frame2->next = frame1;
	glo->frames = frame1;
}

/*Finish initialization of global structure after parsing(need map dimensions)*/
void	ft_init_post_parsing_main(t_global *glo, char debug)
{
	fts_init_post_xvars_init(glo, debug);
	fts_init_post_win_init(glo, debug);
	//ft_init_post_textures_init(glo, debug); 
	fts_init_post_frames_init(glo, debug);
	/*
	to do : hooks init
	*/
	if (debug)
		write(1, "- End of initialisation  -\n\n", 28);
}
