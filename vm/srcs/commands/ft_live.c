/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:51:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/21 14:51:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg)
{
	int counter;

	arg = NULL;
	pc->is_alive = 1;
	game_info->live_count++;
	counter = 0;
	while (counter != game_info->players_num)
	{
		if (params[0] == game_info->names[counter])
		{
			game_info->live[counter] = 1;
			game_info->last_live = params[0];
			break ;
		}
		counter++;
	}
	pc->position = game_info->working_pos;
}
