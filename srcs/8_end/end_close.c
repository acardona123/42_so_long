/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:02:07 by acardona          #+#    #+#             */
/*   Updated: 2023/02/08 01:43:58 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Close the game and free everything properly*/
void	ft_end_close(t_global *glo)
{
	if (DEBUG)
		write(1, "\nProgram end, free all :\n", 25);
	ft_garbage_group_free(&(glo->garb.gbgroup), 0);
	if (DEBUG)
		write(1, " ok\n", 4);
	write(1, "\nThank you for playing, see you soon.\n\n", 39);
}

/*Dispay a victory msg and wait to close the program*/
void	ft_end_victory(t_global *glo)
{
	/*to do*/

	write(1, "Victory !\n", 10);
	ft_end_close(glo);
}
