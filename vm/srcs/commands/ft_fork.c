/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:01:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/28 19:01:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg)
{
	unsigned short	eding_pos;
	int				new_pos;

	arg = NULL;
	eding_pos = (short)params[0] % IDX_MOD;
	new_pos = pc->position;
	while (eding_pos--)
		new_pos = MAKE_CYCLE(new_pos);
	add_pc(pc, pc->reg[1], new_pos);
	copy_pc(pc);
	pc->position = game_info->working_pos;
}
