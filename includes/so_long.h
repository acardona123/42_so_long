/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:20 by acardona          #+#    #+#             */
/*   Updated: 2023/02/06 03:23:35 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "garbage.h"
# include "libft_so_long.h"
# include "get_next_line.h"

# define WIDTH 1024
# define HEIGHT 1024
# define CHUNK_SIZE 32

# define MAP_NAME "includes/maps/valid/map_valid_7x4_simple.txt"
# define PATH_EXIT "includes/textures/exit.xpm"
# define PATH_GROUND "includes/textures/ground.xpm"
# define PATH_PLAYER "includes/textures/penguin16x16.xpm"
# define PATH_WALL "includes/textures/wall.xpm"
# define PATH_COLLECT "includes/textures/collectible.xpm"

# define ERR_MLX 3



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
	t_texture_tail	*exit;
	t_texture_tail	*ground;
	t_texture_tail	*player;
	t_texture_tail	*wall;
	t_texture_tail	*fruit;
}	t_texture_pack;

typedef struct s_frames
{
	t_data			*frame;
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
	int					move_cpt;
	char				**map;
	int					map_h;
	int					map_w;
}	t_global;

/* 

===== 0_GARBAGE =====
voir garbage.h; 
 garbage_collector_init.c */
void		ft_garbage_collector_init(t_global *glo, char debug);
/*

===== 1_INIT PRE PARSING=====
 init_pre_0main.c */
void		ft_init_pre_parsing_main(t_global *glo, char debug);
/*

===== 2_PARSING =====
 parsing_0main.c */
void		ft_parsing_map_error(t_garb_list **garb, int error_id);
void		ft_parsing_main(t_global *glo, char *map_name, char debug);
/*
 parsing_file_to_map.c */
void		ft_parsing_file_to_map(t_global *glo, int *fd, char debug);
/*
 parsing_map_check_content.c */
void		ft_parsing_check_map_content(t_global *glo, char debug);
/*
 parsing_map_check_path.c*/
void		ft_parsing_check_map_path(t_global *glo, char debug);
/*

===== 3_INIT POST PARSING=====
init_post_0main.c */
void		ft_init_post_parsing_main(t_global *glo, char debug);
/*
 init_post_textures.c*/
void		ft_init_post_textures_init(t_global *glo, char debug);
/*


===== 8_END =====
 end_close.c*/
void		ft_end_close(t_global *glo, char debug);
/*

===== 9_TOOLS =====
 tools_img_blend.c*/
void		ft_blend_pxl(unsigned int *pxl_dst, unsigned int *pxl_top);
void		ft_blend_img(t_data *back, t_data *top, int x0, int y0);
/*
 tools_img_new_img.c*/
t_data		*ft_tools_img_new(t_global *glo, int width, int height);
/*
 tools_img_resize.c */
void		ft_tools_resize_img(t_global *glo, t_data *img, int size);
/*
 tools_error_exit.c*/
void		ft_error_exit(t_garb_list **garb, int error_id, char *error_msg);
/*
 tools_find_map_elem.c */
void		ft_tools_elem_find(t_global *glo, char **map, char elem,
				t_coord *dst);
/*
 tools_map_elem_count.c */
long int	ft_tools_elem_count(char **map, char elem);
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