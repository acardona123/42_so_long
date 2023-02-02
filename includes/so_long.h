/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:20 by acardona          #+#    #+#             */
/*   Updated: 2023/02/02 20:49:00 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "garbage.h"
# include "libft_so_long.h"
# include "get_next_line.h"
# define WIDTH 1024
# define HEIGHT 1024
# define PATH_EXIT ""
# define PATH_GROUND ""
# define PATH_PLAYER ""
# define PATH_WALL ""
# define PATH_FRUIT ""

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

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
	char 				**map;
	int					map_h;
	int					map_w;
	int					chunk_size;
}	t_global;

/* 

===== GARBAGE =====
voir garbage.h; 
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

===== PARSING =====
 parsing_file_to_map.c */
void		ft_parse_file_to_map(t_global *glo, int *fd, char **map, char debug);
/*
 parsing_map_check_content.c */
void		ft_parse_check_map_content(t_global *glo, char **map, char debug);
/*
 parsing_map_check_path.c*/
void		ft_parse_check_map_path(t_global *glo, char **map, char debug);
/*
 parsing_main.c */
void		ft_map_error(t_garb_list **garb, int error_id);
void		ft_parse_main(t_global *glo, char *map_name, char debug);
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
/*
 tools_error_exit.c*/
void		ft_error_exit(t_garb_list **garb, int error_id, char *error_msg);
/*
 tools_find_map_elem.c */
t_coord		ft_tools_find_map_elem(t_global *glo, char **map, char elem);

#endif