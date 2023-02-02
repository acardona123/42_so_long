/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:42:28 by acardona          #+#    #+#             */
/*   Updated: 2023/02/02 20:42:14 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*if map error : stop progam with appropriate msg. Else : nothing*/
void	ft_map_error(t_garb_list **garb, int error_id)
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
			"Map error : too many exits / start points.");
	if (error_id == 5)
		ft_error_exit(garb, 1,
			"Map error : missing starting point / exit / collectible");
	if (error_id == 6)
		ft_error_exit(garb, 1, "Map error : not solvable.");
}

void	ft_parse_main(t_global *glo, char *map_name, char debug)
{
	int		*fd;

	if (debug)
		write(1, "=> map init:\n", 13);
	fd = ft_my_malloc(glo->garb.gbfd, sizeof(int));
	*fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error_exit(&glo->garb.gbgroup, 1, "Map file not found.");
	ft_parse_file_to_map(glo, *fd, glo->map, debug);
	ft_parse_check_map_content(glo, glo->map, debug);
	ft_parse_check_map_path(glo, glo->map, debug);
	if (debug)
		write(1, " ok\n", 4);
}
