/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:05:00 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/14 18:04:30 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	last_check(t_game_info *game_info, t_pc **pc)
{
	int		counter;
	t_pc	*pc_cpy;

	if (game_info->players_num <= 0)
	{
		counter = 0;
		while (counter != 4)
		{
			del_player(pc, game_info->names[counter]);
			counter++;
		}
		game_info->end_game = 1;
	}
	else
	{
		ft_bzero(game_info->live, 4 * 4);
		game_info->live_count = 0;
		pc_cpy = *pc;
		while (pc_cpy)
		{
			pc_cpy->is_alive = 0;
			pc_cpy = pc_cpy->next;
		}
	}
}

void	ft_p(t_pc *pointer)
{
	t_pc *tmp;

	tmp = pointer->next;
	pointer->next = pointer->next->next;
	free(tmp);
}

void	check_pc(t_pc **pc)
{
	t_pc *pointer;

	while (1)
	{
		pointer = *pc;
		if (pointer == NULL)
			return ;
		if (!pointer->is_alive)
		{
			*pc = pointer->next;
			free(pointer);
			pointer = NULL;
		}
		else
			break ;
	}
	while (pointer->next)
	{
		if (!pointer->next->is_alive)
			ft_p(pointer);
		else
			pointer = pointer->next;
	}
}

int		escape_pl(t_pc **pc)
{
	t_pc *pointer;

	pointer = *pc;
	while (pointer)
	{
		if (pointer->is_alive)
			return (1);
		pointer = pointer->next;
	}
	return (0);
}

void	make_check(t_game_info *game_info, t_pc **pc)
{
	int counter;

	counter = game_info->players_num;
	check_pc(pc);
	while (counter--)
	{
		if (game_info->live[counter] == 0 && !escape_pl(pc))
		{
			del_player(pc, game_info->names[counter]);
			game_info->players_num--;
		}
		else
			game_info->live[counter] = 0;
	}
	if (game_info->live_count > NBR_LIVE)
	{
		game_info->cycle_to_die -= CYCLE_DELTA;
		game_info->max_checks = MAX_CHECKS;
	}
	else
		game_info->max_checks--;
	last_check(game_info, pc);
}
