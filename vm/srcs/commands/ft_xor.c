/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:45:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/28 18:45:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_xor(unsigned int *params, t_pc *pc, t_game_info *game_info, int *arg)
{
	unsigned int	numbers[2];
	int				counter;
	int				pos_counter;

	counter = 0;
	while (counter != 2)
	{
		if (arg[counter] == REG_CODE)
			numbers[counter] = pc->reg[params[counter]];
		else if (arg[counter] == DIR_CODE)
			numbers[counter] = params[counter];
		else if (arg[counter] == IND_CODE)
		{
			params[counter] = params[counter] % IDX_MOD;
			pos_counter = pc->position;
			while (params[counter]--)
				pos_counter = MAKE_CYCLE(pos_counter);
			numbers[counter] = parse_param(4, game_info, pos_counter, 0);
		}
		counter++;
	}
	pc->position = game_info->working_pos;
	pc->reg[params[2]] = numbers[0] ^ numbers[1];
	CARRY(pc->reg[params[2]], pc->carry);
}
