/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:24:26 by acardona          #+#    #+#             */
/*   Updated: 2023/02/14 04:59:41 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Verifies if the map is a .ber*/
void	ft_parsing_check_map_name(t_global *glo, char *map_name)
{
	int	i;
	int	j;

	if (!map_name)
		ft_parsing_map_error(&glo->garb.gbgroup, 7);
	i = 0;
	while (map_name[i])
		i++;
	j = 0;
	while (j < 4)
	{
		if (map_name[i - 1 - j] != ".ber"[3 - j])
			ft_parsing_map_error(&glo->garb.gbgroup, 7);
		j++;
	}
}
