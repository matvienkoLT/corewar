/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:06:43 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 19:06:45 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	game_init(t_game_info *game_info, int players_num, t_info **info)
{
	int counter;

	game_info->players_num = players_num;
	game_info->cycle_to_die = CYCLE_TO_DIE;
	game_info->max_checks = MAX_CHECKS;
	game_info->live_count = 0;
	game_info->vis_num = players_num;
	game_info->last_live = -5;
	ft_bzero(game_info->live, game_info->players_num);
	ft_memset(game_info->field, '\0', MEM_SIZE);
	ft_memset(game_info->colors, 9, MEM_SIZE);
	game_info->end_game = 0;
	counter = 0;
	while (counter != 4)
	{
		game_info->live[counter] = 0;
		counter++;
	}
	game_info->info = info;
}

void	start_vm(t_info **info, int players_num, int *flags)
{
	t_pc		*pc;
	t_game_info	*game_info;

	game_info = (t_game_info*)malloc(sizeof(t_game_info));
	game_init(game_info, players_num, info);
	pc = pc_init(game_info->players_num, info, game_info);
	make_field(game_info, info, pc);
	if (flags[0] && !flags[1])
		ft_visualisation(pc, game_info);
	else
	{
		pc_algo(pc, game_info, flags[1]);
	}
}
