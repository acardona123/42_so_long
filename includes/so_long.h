/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:20 by acardona          #+#    #+#             */
/*   Updated: 2023/01/22 01:30:39 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_garbage
{
	t_list	**parent_group;
	void	(*del_function)(void *);
	t_list	*first;
}	t_garbage;

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
	t_data			*frame;
	struct s_frames	*next;
}	t_frames;

typedef struct s_global
{
	void			*mlx;
	void			*win;
	t_texture_pack	*textures;
	t_list			*garb_group;
	t_garbage		*garb_img;
	t_garbage		*garb_win;
	t_garbage		*garb_ptr;
}	t_global;

/*garbage_collector_0_groups.c*/
void		ft_garbage_group_add_garb(t_list **group, t_garbage *garb);
int			ft_garbage_group_free(t_list **group, int error_exit);

/*garbage_collector_1_units.c*/
t_garbage	*ft_garbage_init(t_list	**group, void (*del)(void *));
int			ft_garbage_free_one(t_garbage *garb, void *content_target);
int			ft_garbage_free(t_garbage *garb, int error_exit);
int			ft_garbage_add(t_garbage *garb, void *ptr);
int			ft_my_malloc(t_garbage *garb, void **dst, size_t size);

/*transparency.c*/
void		ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_blend_pxl(unsigned int *pxl_dst, unsigned int *pxl_top);
void		ft_blend_img(t_data *back, t_data *top, int x0, int y0);

#endif