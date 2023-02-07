/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_img_blend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:50:07 by acardona          #+#    #+#             */
/*   Updated: 2023/02/07 01:31:11 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*modify pxl_dst by supperposing pxl_top to it, deals with transparency.*/
void	ft_tools_pxl_blend_pxl(unsigned int *pxl_dst, unsigned int *pxl_top)
{
	int				pxl;
	unsigned char	tr;

	if (((*pxl_dst) << 8) == ((*pxl_top) << 8) || (*pxl_top) >> 24 == 0xFF)
		return ;
	if (!((*pxl_top) >> 24))
		*pxl_dst = *pxl_top;
	else
	{
		tr = (*pxl_top) >> 24;
		pxl = ((*pxl_dst & 0xFF0000) * (255 - tr)
				+ (*pxl_top & 0xFF0000) * tr) / 255;
		pxl <<= 2;
		pxl += ((*pxl_dst & 0x00FF00) * (255 - tr)
				+ (*pxl_top & 0x00FF00) * tr) / 255;
		pxl <<= 2;
		pxl += ((*pxl_dst & 0x0000FF) * (255 - tr)
				+ (*pxl_top & 0x0000FF) * tr) / 255;
		*pxl_dst = pxl;
	}
}

/*Mofiy back img puting top img at x0,y0 & mixing colors if transparency*/
void	ft_tools_img_blend(t_data *back, t_data *top, int x0, int y0)
{
	int	x;
	int	y;

	if (back->bpp != top->bpp
		|| back->bpp != 32)
		return ;
	y = -1;
	while (++y + y0 < ((t_img *)back->img)->height
		&& y < ((t_img *)top->img)->height)
	{
		x = -1;
		while (++x + x0 < ((t_img *)back->img)->width
			&& x < ((t_img *)top->img)->width)
		{
			ft_tools_pxl_blend_pxl((unsigned int *)((back->addr) + (x0 + x)
					* (back->bpp / 8) + (y0 + y)
					* (back->line_length)), (unsigned int*)((top->addr) + x
					* (top->bpp / 8) + y * top->line_length));
		}
	}
}

/*============ TESTS ================*/
// void ft_square(t_data *data, int x_square, int y_square, int size, int color)
// {
// 	int	x;
// 	int	x0;
// 	int	y;
// 	int	y0;

// 	 if (x_square >= ((t_img*)(data->img))->width
// 	 	||y_square >= ((t_img*)(data->img))->height)
// 		return ;
// 	x0 = x_square * (x_square >= 0);
// 	y0 = y_square * (y_square >= 0);
// 	y = y0;
// 	while (y < y_square + size && y < ((t_img*)data->img)->height)
// 	{
// 		x = x0 - 1;
// 		while (++x < x0 + size && x < ((t_img*)(data->img))->width)
// 			ft_my_mlx_pixel_put(data, x, y, color);
// 		y++;
// 	}
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	t_data	background;
// 	t_data	front1;
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Ma fenetre");
// 	background.img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	background.addr = mlx_get_data_addr(background.img,
// 	&background.bpp, &background.line_length, &background.endian);
// 	ft_square(&background, 0, 0, 10, 0x00FF0000);
// 	ft_square(&background, WIDTH - 10, 0, 10, 0x00FF0000);
// 	ft_square(&background, 0, HEIGHT - 10, 10, 0x00FF0000);
// 	ft_square(&background, WIDTH - 10, HEIGHT - 10, 10, 0x00FF0000);
// 	ft_square(&background, 10, 10, WIDTH - 20, 0x0000FF00);
// 	mlx_put_image_to_window(mlx, win, background.img, 0, 0);
// 	sleep(1);
// 	front1.img = mlx_new_image(mlx, WIDTH / 2, HEIGHT / 2);
// 	front1.addr = mlx_get_data_addr(front1.img, &front1.bpp, &front1.line_length, &front1.endian);
// 	ft_square(&front1, 0, 0, WIDTH / 4, 0x000000FF);
// 	ft_square(&front1, 0, WIDTH / 4, WIDTH / 4, 0x100000FF);
// 	ft_square(&front1, WIDTH / 4, 0, WIDTH / 4, 0x600000FF);
// 	ft_square(&front1, WIDTH / 4, WIDTH / 4, WIDTH / 4, 0xFF0000FF);
// 	// mlx_put_image_to_window(mlx, win, front1.img, 0, 0);
// 	ft_tools_img_blend(&background, &front1, 10, 10);
// 	printf("Toto\n");
// 	mlx_put_image_to_window(mlx, win, background.img, 0, 0);
// 	mlx_loop(mlx);
// 	// mlx_put_image_to_window(mlx, win, );
// 	return (0);
// }
