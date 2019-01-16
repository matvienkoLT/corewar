/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:54:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/28 18:54:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		if_ind(unsigned int param, t_pc *pc, t_game_info *game_info)
{
	unsigned short	position;
	int				pos_counter;

	position = (short)param % IDX_MOD;
	pos_counter = pc->position;
	while (position--)
		pos_counter = MAKE_CYCLE(pos_counter);
	return (parse_param(4, game_info, pos_counter, 0));
}

void			ft_ldi(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg)
{
	int				counter;
	unsigned short	numbers[2];
	int				pos_counter;
	unsigned short	tmp;

	counter = 0;
	while (counter != 2)
	{
		if (arg[counter] == REG_CODE)
			numbers[counter] = pc->reg[params[counter]];
		else if (arg[counter] == DIR_CODE)
			numbers[counter] = params[counter];
		else if (arg[counter] == IND_CODE)
			numbers[counter] = if_ind(params[counter], pc, game_info);
		counter++;
	}
	tmp = ((short)numbers[0] + (short)numbers[1]) % IDX_MOD;
	pos_counter = pc->position;
	while (tmp--)
		pos_counter = MAKE_CYCLE(pos_counter);
	pc->reg[params[2]] = parse_param(4, game_info, pos_counter, 0);
	pc->position = game_info->working_pos;
}
