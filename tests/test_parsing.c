#include "../includes/so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_global	glo;
	char		debug;

	debug = 0;
	if (ac != 2)
	{
		printf("1 arg requiered : map_name");
	}
	ft_init_pre_parsing_main(&glo, debug);
	ft_parsing_main(&glo, av[1], debug);
	return (0);
}
