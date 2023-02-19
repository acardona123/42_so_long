
# include <X11/X.h>
# include <X11/keysym.h>
# include "../project/includes/mlx/mlx.h"
# include "../project/includes/mlx/mlx_int.h"

int main()
{
	int i;
	int j;
	int Nmax;
	int n;
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "test");
	mlx_loop(mlx);
	return (0);
}

// cc -L../project/includes/mlx -lmlx -lXext -lX11 gradient.c