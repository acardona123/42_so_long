/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:42:28 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 01:37:17 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*if map error : stop progam with appropriate msg. Else : nothing*/
void	ft_parsing_map_error(t_garb_list **garb, int error_id)
{
	if (!error_id)
		return ;
	if (error_id == 1)
		ft_error_exit(garb, 1, "Map error : not rectangular.");
	if (error_id == 2)
		ft_error_exit(garb, 1, "Map error : not closed.");
	if (error_id == 3)
		ft_error_exit(garb, 1, "Map error : forbidden component.");
	if (error_id == 4)
		ft_error_exit(garb, 1,
			"Map error : too many exit/start points.");
	if (error_id == 5)
		ft_error_exit(garb, 1,
			"Map error : missing starting point/exit/collectible.");
	if (error_id == 6)
		ft_error_exit(garb, 1, "Map error : not solvable.");
}

void	ft_parsing_main(t_global *glo, char *map_name)
{
	int		*fd;

	if (DEBUG)
		write(1, "=> map init:\n", 13);
	fd = ft_my_malloc(glo->garb.gbfd, sizeof(int));
	*fd = open(map_name, O_RDONLY);
	if (*fd < 0)
		ft_error_exit(&glo->garb.gbgroup, 1, "Map file not found.");
	ft_parsing_file_to_map(glo, fd);
	ft_parsing_check_map_content(glo);
	ft_parsing_check_map_path(glo);
	if (DEBUG)
		write(1, " ok\n", 4);
}
