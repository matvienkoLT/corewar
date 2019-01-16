/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:52:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/21 14:52:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_ld(unsigned int *params, t_pc *pc, t_game_info *game_info, int *arg)
{
	int				pos_counter;

	if (arg[0] == DIR_CODE)
		pc->reg[params[1]] = params[0];
	else if (arg[0] == IND_CODE)
	{
		params[0] = params[0] % IDX_MOD;
		pos_counter = pc->position;
		while (params[0]--)
			pos_counter = MAKE_CYCLE(pos_counter);
		pc->reg[params[1]] = parse_param(4, game_info, pos_counter, 0);
	}
	pc->position = game_info->working_pos;
	CARRY(pc->reg[params[1]], pc->carry);
}
