/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:44:00 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/03 11:44:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_lfork(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg)
{
	unsigned short	eding_pos;
	int				new_pos;

	arg = NULL;
	eding_pos = (short)params[0];
	new_pos = pc->position;
	while (eding_pos--)
		new_pos = MAKE_CYCLE(new_pos);
	add_pc(pc, pc->pl_number, new_pos);
	copy_pc(pc);
	pc->position = game_info->working_pos;
}
