#include "../includes/so_long.h"

int main()
{
	void *mlx;
	void *win;
	t_data data;
	int w;
	int h;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1024, 2048, "Essai img");
	data.img = mlx_xpm_file_to_image(mlx, "includes/textures/exit.xpm", &w, &h);
	// data.img = mlx_new_image(mlx, 128, 128);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
	mlx_put_image_to_window(mlx, win, data.img, 120,120);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, data.img);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}

//cc -Wall -Werror -Wextra -g -I./includes -I.includes/mlx tests/test_img.c -Lincludes/mlx -lmlx -lXext -lX11 -lm && ./a.out