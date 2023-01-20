/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:20 by acardona          #+#    #+#             */
/*   Updated: 2023/01/19 22:54:37 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "mlx_int.h"
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;


/*transparency.c*/
void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_blend_pxl(unsigned int *pxl_dst, unsigned int *pxl_top);
void	ft_blend_img(t_data *back, t_data *top, int x0, int y0);

#endif