/*
 clear && gcc -Werror -Wextra -Wall -g tests/test_garbage_collector.c srcs/garbage/garbage_collector_0_groups.c srcs/garbage/garbage_collector_1_units.c -o test && valgrind  ./test && rm test
*/

#include "../includes/so_long.h"

#include <stdio.h>

int	main(void)
{
	t_global	glo;
	int			test;

	glo.local_endian = 0;
	glo.garb.gbgroup = 0;
	glo.garb.gbimg = 0;
	glo.garb.gbptr = 0;
	glo.garb.gbwin = 0;
	glo.garb.gbxvar = 0;
	glo.mlx = 0;
	glo.win = 0;
	glo.textures = 0;
	glo.frames = 0;
	glo.cpt_move = 0;

	ft_init_pre_parsing_main (&glo, 0);
	glo.map_h = 100; /*3 lignes simulant la reussite du parsing*/
	glo.map_w = 200;
	ft_init_post_parsing_main(&glo, 0);

	test = 2;

	if (test == 0)
		ft_garbage_free_one(glo.garb.gbwin, glo.win);
	else if (test == 1)
	{
		ft_garbage_free(glo.garb.gbimg, 0);
		ft_garbage_free(glo.garb.gbwin, 0);
		ft_garbage_free(glo.garb.gbxvar, 0);
		ft_garbage_free(glo.garb.gbptr, 0);
	}
	else if (test == 2)
	{
		ft_garbage_group_free(&(glo.garb.gbgroup), 
		0);
		//free(glo.mlx);
	}

	//ft_garbage_free(gl.gbimg, 0);

	// ft_garbage_free_one(&gl.gbimg, (void *)ptr2);
	//ft_garbage_free_one(gl.gbimg, (void *)ptr3);
	// ft_garbage_group_free(&(glo.garb.gbgroup), 0);
	// printf("Reste apres free one : %p, %p\n", gl.gbimg, NULL);
	return (0);
}
