/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_open_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:47:02 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 21:37:56 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Open exit : change texture on map and set variable exit_open to 1 in t_glo*/
void	fts_game_open_exit(t_global *glo)
{
	t_coord	exit;

	ft_tools_elem_find(glo, glo->map, 'E', &exit);
	ft_tools_img_blend(glo->background, &glo->textures.exit_open->data,
		exit.x * CHUNK_SIZE, exit.y * CHUNK_SIZE);
	glo->exit_open = 1;
}
