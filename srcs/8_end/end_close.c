/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:02:07 by acardona          #+#    #+#             */
/*   Updated: 2023/01/23 10:07:00 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Close the game and free everything properly*/
void	ft_end_close(t_global *glo, char debug)
{
	if (debug)
		write(1, "\nProgram end, free all :\n", 25);
	ft_garbage_group_free(&(glo->garb.gbgroup), 0);
	if (debug)
		write(1, " ok\n", 4);
	write(1, "\nThank you for playing, see you soon.\n\n", 39);
}
