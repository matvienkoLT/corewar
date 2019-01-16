/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:10:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/20 18:10:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void (*g_funx[17])(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg) =
{
	NULL, ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and,
	ft_or, ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork,
	ft_lld, ft_lldi, ft_lfork, ft_aff
};

int		starting_launch(t_pc *pc, unsigned int *params, int *arg,
		t_game_info *game_info)
{
	static	int counter;

	if (!pc->is_error)
		g_funx[hextodec(pc->command.code)](params, pc, game_info, arg);
	else
		pc->position = game_info->working_pos;
	pc->is_error = 0;
	ft_bzero(arg, 3 * 4);
	free(params);
	counter++;
	return (1);
}
