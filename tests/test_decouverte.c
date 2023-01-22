/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decouverte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:21:11 by acardona          #+#    #+#             */
/*   Updated: 2023/01/21 23:21:52 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>
#include <math.h>

/*========== GEOMETRIC SHAPES =========*/


void ft_square(t_data *data, int x_square, int y_square, int size, int color)
{
	int	x;
	int	y;

	x = (x_square - size / 2) * ((x_square - size / 2) >= 0);
	while (x < WIDTH && x < x_square + size / 2)
	{
		y = (y_square - size / 2) * ((y_square - size / 2) >= 0);;
		while (y < HEIGHT && y < y_square + size / 2)
		{
			ft_my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}
void ft_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
	int	x;
	int	y0;
	int	y;

	if (radius <= 0 || center_x + radius < 0 || center_x - radius > WIDTH
		|| center_y + radius < 0 || center_y - radius > HEIGHT)
		return ;
	if (center_x - radius >= 1)
		x = center_x - radius - 1;
	else
		x = 0;
	if (center_y - radius >= 1)
		y0 = center_y - radius - 1;
	else
		y0 = 0;
	while (x <= WIDTH && x <= center_x + radius + 1)
	{
		y = y0;
		while (y <= HEIGHT && y <= center_y + radius + 1)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius)
				ft_my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}
int ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	else
		return (n);
}
void ft_hexagon(t_data *data, int x_hex, int y_hex, int	size, int color)
{
	int	x;
	int	y;

	x = x_hex - size / 2;
	while (x < WIDTH && x < x_hex + size / 2 + size % 2)
	{
		y = y_hex - size / 2;
		while (y < HEIGHT && y < y_hex + size / 2 + size % 2)
		{
			if (ft_abs(x - x_hex) + ft_abs(y - y_hex) <= 3 * size / 4
				&& ft_abs(x - x_hex) <= size / 2 && ft_abs(y - y_hex) <= size / 2)
				ft_my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}
void	ft_rainbow(t_data *data, int center_x, int center_y, int radius_min, int radius_max)
{
	int	x;
	int	y0;
	int	y;
	int	r;
	int	color;

	if (radius_max <= radius_min || radius_min < 0 || center_x + radius_max < 0 || center_x - radius_max > WIDTH
		|| center_y < 0 || center_y - radius_max > HEIGHT)
		return ;
	if (center_x > radius_max)
		x = center_x - radius_max - 1;
	else
		x = 0;
	if (center_y > radius_max)
		y0 = center_y - radius_max - 1;
	else
		y0 = 0;
	while (x <= WIDTH && x <= center_x)
	{
		y = y0;
		while (y <= HEIGHT && y <= center_y)
		{
			r = sqrt((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y));
			if (r <= radius_min + (radius_max - radius_min) / 2  + (radius_max - radius_min) % 2 && r >= radius_min)
			{
				color = ((r - radius_min) * 0xFF * 2 / (radius_max - radius_min));
				color = (color << 8) + 0xFF - color;
				ft_my_mlx_pixel_put(data, x, y, color);
				ft_my_mlx_pixel_put(data, center_x + radius_max - x, y, color);
				ft_my_mlx_pixel_put(data, center_x  + radius_max - x, center_y + radius_max - y , color);
				ft_my_mlx_pixel_put(data, x, center_y + radius_max - y, color);
			}
			else if (r <= radius_max && r > (radius_max - radius_min) / 2 + radius_min)
			{
				color = ((r - radius_min) * 255 * 2 / (radius_max - radius_min));
				color = (color << 16) + ((255 - color) << 8);
				ft_my_mlx_pixel_put(data, x, y, color);
				ft_my_mlx_pixel_put(data, center_x + radius_max - x, y, color);
				ft_my_mlx_pixel_put(data, center_x  + radius_max - x, center_y + radius_max - y , color);
				ft_my_mlx_pixel_put(data, x, center_y + radius_max - y, color);
			}
			y++;
		}
		x++;
	}
}

void ft_disk_shadow(t_data *data, int center_x, int center_y, int radius_min, int radius_max)
{
	int	x;
	int	y;
	int	r;
	unsigned int	pxl;

	y = center_y - radius_max;
	while (y < HEIGHT && y <= center_y + radius_max)
	{
		x = center_x - radius_max;
		while (x < WIDTH && x <= center_x + radius_max)
		{
			r = (int)sqrt((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y));//((r - radius_min) * 255 / (radius_max - radius_min)) << 24
			
			if (r >= radius_min && r < radius_max)
			{
				// pxl = 255;
				// ft_my_mlx_pixel_put(data, x, y, 255);
				ft_blend_pxl((unsigned int *)(data->addr + x * data->bits_per_pixel / 8 + y * data->line_length), &pxl);
			}
			x++;
		}
		printf("y : %d \n", y);
		y++;
	}
}

// void ft_circle_rainbow(t_data *data, int center_x, int center_y, int radius)
// {
// 	int	x;
// 	int	y;
// 	int	y0;

// 	if (center_x - radius || y0 < 0)
// 		return ;
	
// }

/*

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_circle(&img, 70, 70, 60, 0x00FF0000);
	ft_square(&img, 70, 70, 70, 0x0000FF00);
	ft_hexagon(&img, 70, 70, 40, 0x000000FF);
	ft_rainbow(&img, WIDTH / 2, HEIGHT/2, 50, HEIGHT / 2 - 10);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_pixel_put(mlx, mlx_win, 70, 70, 0xFFFF0000);
	mlx_loop(mlx);
	//printf("Hauteur : %d\n", ((t_img *)img.img)->width);
	return (0);
}
*/
/*===============================================================================================================*/

/*===== HOOKS =====*/

/**/
int	ft_key_hook(int key_code, t_global *param)
{
	if (key_code == XK_w || key_code == XK_Up)
		printf("w\n");
	else if (key_code == XK_s || key_code == XK_Down)
		printf("s\n");
	else if (key_code == XK_a || key_code == XK_Left)
		printf("a\n");
	else if (key_code == XK_d || key_code == XK_Right)
		printf("d\n");
	else if (key_code == XK_Escape)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit (0);
	}
	// else//
	// 	printf("%d\n", key_code);//
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	printf("Bouton %d en (%d, %d)\n", button, x, y);//
	return (0);
}

int	ft_expose_hook(void *param)
{
	(void)param;

	printf("Expose hook actived\n");
	return (0);
}

int	main(void)
{
	t_global	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	// ft_circle(&img, 70, 70, 60, 0x00FF0000);
	// ft_square(&img, 70, 70, 70, 0x0000FF00);
	// ft_hexagon(&img, 70, 70, 40, 0x000000FF);
	//ft_rainbow(&img, WIDTH / 2, HEIGHT/2, 10, HEIGHT / 2 - 10);
	ft_square(&img, WIDTH / 2, WIDTH / 2, WIDTH, 0x0000FF00);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_pixel_put(vars.mlx, vars.win, 70, 70, 0xFFFF0000);
	ft_disk_shadow(&img, WIDTH / 2, WIDTH / 2, 10, WIDTH / 2 - 20);
	mlx_key_hook(vars.win, &ft_key_hook, &vars); 
	mlx_mouse_hook(vars.win, &ft_mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
