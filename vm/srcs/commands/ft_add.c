/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:11:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/28 17:11:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_add(unsigned int *params, t_pc *pc, t_game_info *game_info, int *arg)
{
	arg = NULL;
	pc->position = game_info->working_pos;
	pc->reg[params[2]] = pc->reg[params[0]] + pc->reg[params[1]];
	CARRY(pc->reg[params[2]], pc->carry);
}
