/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:46:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/28 18:46:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg)
{
	int				new_pos;
	unsigned short	position;

	arg = NULL;
	if (pc->carry == 0)
	{
		pc->position = game_info->working_pos;
		return ;
	}
	position = (short)params[0] % IDX_MOD;
	new_pos = pc->position;
	while (position--)
		new_pos = MAKE_CYCLE(new_pos);
	pc->position = new_pos;
}
