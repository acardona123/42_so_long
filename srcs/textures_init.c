/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:16:13 by acardona          #+#    #+#             */
/*   Updated: 2023/01/21 23:33:38 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_texture_tail(t_global *glob, t_texture_tail **dst, char *path)
{
	ft_my_malloc(&glob->garbage, (void *)dst, sizeof(t_texture_tail));
	(*dst)->path = path;
	(*dst)->data->img = mlx_xpm_file_to_image(glob->mlx, path, &(*dst)->img_width, &(*dst)->img_width);
	
	if (!(*dst)->data->img)
	{
		free(dst);
		return (1);
	}
	return (0);
}
