/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:05:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/26 13:05:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_st(unsigned int *params, t_pc *pc, t_game_info *game_info, int *arg)
{
	int				counter;
	unsigned char	tmp;
	unsigned short	position;

	ft_reset_highlighting((unsigned char*)game_info->colors, pc->pl_number);
	if (arg[1] == REG_CODE)
		pc->reg[params[1]] = pc->reg[params[0]];
	else if (arg[1] == IND_CODE)
	{
		position = (short)(params[1]) % IDX_MOD + pc->position;
		while (position >= MEM_SIZE)
			position -= MEM_SIZE;
		counter = 4;
		while (counter--)
		{
			tmp = (unsigned char)(pc->reg[params[0]] >> counter * 8);
			game_info->field[position] = tmp;
			game_info->colors[position] = pc->pl_number;
			if (++position == MEM_SIZE)
				position = 0;
		}
	}
	pc->position = game_info->working_pos;
}
