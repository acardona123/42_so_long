/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:20 by acardona          #+#    #+#             */
/*   Updated: 2023/02/12 05:22:36 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define DEBUG 0

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# include "garbage.h"
# include "libft_so_long.h"
# include "get_next_line.h"

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define CHUNK_SIZE 64

# define MAP_NAME "../maps/valid/map_valid_7x7_exit_test.txt"
# define PATH_EXIT_LOCK "includes/textures/exit_locked.xpm"
# define PATH_EXIT_OPEN "includes/textures/exit_open.xpm"
# define PATH_GROUND "includes/textures/ground.xpm"
# define PATH_PLAYER "includes/textures/penguin16x16.xpm"
# define PATH_WALL "includes/textures/wall.xpm"
# define PATH_COL_ON "includes/textures/collectible_on.xpm"
# define PATH_COL_OFF "includes/textures/collectible_off.xpm"
# define PATH_SIGN "includes/textures/sign.xpm"
# define PATH_VICTORY "includes/textures/victory.xpm"

# define ERR_MLX 3

# define SPEED_RATIO 1
# define MAX_CAM_SPEED 5

#include <stdio.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		pix_width;
	int		pix_height;
	int		endian;
}	t_data;

typedef struct s_texture_tail
{
	char	*path;
	int		img_width;
	int		img_height;
	t_data	data;
}	t_texture_tail;

typedef struct s_texture_pack
{
	t_texture_tail	*exit_lock;
	t_texture_tail	*exit_open;
	t_texture_tail	*ground;
	t_texture_tail	*player;
	t_texture_tail	*wall;
	t_texture_tail	*col_on;
	t_texture_tail	*col_off;
	t_texture_tail	*stat_sign;
	t_texture_tail	*victory;
}	t_texture_pack;

typedef struct s_frames
{
	t_data			*frame;
	t_coord			co_player;
	struct s_frames	*next;
}	t_frames;

typedef struct s_global
{
	int					local_endian;
	t_garbage_resume	garb;
	void				*mlx;
	void				*win;
	t_texture_pack		textures;
	t_frames			*frames;
	t_data				*background;
	char				**map;
	int					map_h;
	int					map_w;
	int					map_ph;
	int					map_pw;
	int					cpt_col;
	int					cpt_move;
	int					exit_open;
	int					cam_lock;
	t_coord				cam_movable;
	int					cam_speed;
	t_coord				cam_co_max;
	t_coord				cam_co_min;
	t_coord				cam_co;
	char				playing;
}	t_global;

typedef struct s_img_cpy
{
	t_data	*img_src;
	t_data	*img_dst;
	t_coord	co_src;
	t_coord	co_dst;
	int		cpy_w;
	int		cpy_h;
}	t_img_cpy;

/* 

===== 0_GARBAGE =====
voir garbage.h; 
 garbage_collector_init.c */
void		ft_garbage_collector_init(t_global *glo);
/*

===== 1_INIT PRE PARSING=====
 init_pre_0main.c */
void		ft_init_pre_parsing_main(t_global *glo);
/*

===== 2_PARSING =====
 parsing_0main.c */
void		ft_parsing_map_error(t_garb_list **garb, int error_id);
void		ft_parsing_main(t_global *glo, char *map_name);
/*
 parsing_file_to_map.c */
void		ft_parsing_file_to_map(t_global *glo, int *fd);
/*
 parsing_map_check_content.c */
void		ft_parsing_check_map_content(t_global *glo);
/*
 parsing_map_check_path.c*/
void		ft_parsing_check_map_path(t_global *glo);
/*


===== 3_INIT POST PARSING=====
init_post_0main.c */
void		ft_init_post_parsing_main(t_global *glo);
/*
 init_post_hooks.c */
void		ft_init_post_hooks_init(t_global *glo);
/*
 init_post_textures.c*/
void		ft_init_post_textures_init(t_global *glo);
/*
 init_post_background.c */
void		ft_init_post_background_init(t_global *glo);
/*


===== 4_GAMEPLAY =====
 gameplay_player_move.c */
int			ft_game_player_move(t_global *glo, int step, t_coord dir);
/*
 gameplay_cam_move.c */
void		ft_game_cam_reset(t_global *glo);
void		ft_game_cam_move(t_global *glo, int step, t_coord dir);
/*
 gameplay_display.c */
void		ft_game_display(t_global *glo);
/*
 gameplay_open_exit.c */
void		fts_game_open_exit(t_global *glo);
/*


===== 8_END =====
 end_close.c*/
void		ft_end_close(t_global *glo, char succes);
/*


===== 9_TOOLS =====
 tools_img_blend.c*/
void		ft_tools_pxl_blend_pxl(unsigned int *pxl_dst,
				unsigned int *pxl_top);
void		ft_tools_img_blend(t_data *back, t_data *top, int x0, int y0);
/*
 tools_img_cpy.c */
void		ft_tools_img_sub_cpy(t_img_cpy cpy);
void		ft_tools_img_cpy(t_data *src, t_data *dst);
/*
 tools_img_new_img.c*/
t_data		*ft_tools_img_new(t_global *glo, int width, int height);
/*
 tools_img_resize.c */
void		ft_tools_resize_img(t_global *glo, t_data *img, unsigned int size);
/*
 tools_error_exit.c*/
void		ft_error_exit(t_garb_list **garb, int error_id, char *error_msg);
/*
 tools_extremum_int.c */
int			ft_tools_min_int(int n1, int n2);
int			ft_tools_max_int(int n1, int n2);
/*
 tools_find_map_elem.c */
void		ft_tools_elem_find(t_global *glo, char **map, char elem,
				t_coord *dst);
/*
 tools_map_elem_count.c */
long int	ft_tools_elem_count(char **map, char elem);
/*
 tools_map_texture_select.c*/
t_data		*ft_chunk_texture_selec(t_global *glo, int x, int y);
/*
 tools_pixel.c */
void		ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
char		*ft_tools_pxl_addr(t_data *data, int x, int y);
/*

===== 10_LIBFT =====
 voir libft_so_long.h

===== 11_GNL =====
 voir get_next_line.h */

#endif