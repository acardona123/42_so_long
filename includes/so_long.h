/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:20 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 16:23:33 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "garbage.h"
# define WIDTH 1024
# define HEIGHT 1024
# define PATH_EXIT ""
# define PATH_GROUND ""
# define PATH_PLAYER ""
# define PATH_WALL ""
# define PATH_FRUIT ""


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_texture_tail
{
	char	*path;
	int		img_width;
	int		img_height;
	t_data	*data;
}	t_texture_tail;

typedef struct s_texture_pack
{
	t_texture_tail	*exit;
	t_texture_tail	*ground;
	t_texture_tail	*player;
	t_texture_tail	*wall;
	t_texture_tail	*fruit;
}	t_texture_pack;

typedef struct s_frames
{
	t_data			frame;
	struct s_frames	*next;
}	t_frames;

typedef struct s_global
{
	int					local_endian;
	t_garbage_resume	garb;
	void				*mlx;
	void				*win;
	t_texture_pack		*textures;
	t_frames			*frames;
	int					move_cpt;
	int					map_h;
	int					map_w;
	int					chunk_size;
}	t_global;

/* 

===== GARBAGE =====
voir garbage.h et 
garbage_collector_init.c */
void		ft_garbage_collector_init(t_global *glo, char debug);
/*

===== INIT =====
init_main_init_pre_parsing.c */
void		ft_init_main_init_pre_parsing(t_global *glo, char debug);
/*
 init_main_init_post_parsing.c */
void		ft_init_main_init_post_parsing(t_global *glo, char debug);
/*
 init_textures.c*/
void		ft_init_textures_init(t_global *glo, char debug);
/*

===== END =====
 end_close.c*/
void		ft_end_close(t_global *glo, char debug);
/*

===== TOOLS =====
 transparency.c*/
void		ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_blend_pxl(unsigned int *pxl_dst, unsigned int *pxl_top);
void		ft_blend_img(t_data *back, t_data *top, int x0, int y0);

#endif