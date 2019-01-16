/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:03:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/19 13:03:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	copy_pc(t_pc *start_pc)
{
	t_pc	*tmp;
	int		counter;

	tmp = start_pc;
	while (tmp->next)
		tmp = tmp->next;
	counter = 0;
	while (counter != REG_NUMBER + 1)
	{
		tmp->reg[counter] = start_pc->reg[counter];
		counter++;
	}
	tmp->is_alive = start_pc->is_alive;
	tmp->carry = start_pc->carry;
	tmp->pl_number = start_pc->pl_number;
	tmp->cycle_num++;
}

t_pc	*add_pc(t_pc *start_pc, unsigned int player_num, int pos)
{
	t_pc	*new_pc;
	t_pc	*tmp;

	new_pc = (t_pc*)malloc(sizeof(t_pc));
	new_pc->next = NULL;
	new_pc->carry = 0;
	new_pc->is_alive = 0;
	new_pc->cycle_num = 0;
	new_pc->command.code = NULL;
	new_pc->position = pos;
	new_pc->is_error = 0;
	new_pc->pl_number = player_num;
	ft_bzero(new_pc->reg, REG_NUMBER + 1 * 4);
	new_pc->reg[1] = 0xffffffff - player_num + 1;
	ft_bzero(new_pc->args, 3 * 4);
	if (start_pc == NULL)
	{
		new_pc->next = NULL;
		return (new_pc);
	}
	tmp = start_pc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_pc;
	return (start_pc);
}

int		find_free_number(int players_number, t_info **info)
{
	int counter;
	int symbol;

	symbol = 1;
	counter = 0;
	while (counter != players_number)
	{
		if (symbol == info[counter]->number)
		{
			symbol++;
			counter = 0;
		}
		counter++;
	}
	return (symbol);
}

t_pc	*pc_init(int players_number, t_info **info, t_game_info *game_info)
{
	int const	position_count = MEM_SIZE / players_number;
	int			counter;
	t_pc		*pc;
	int			pos;
	int			pl_number;

	pc = NULL;
	counter = 0;
	while (counter < players_number)
	{
		if ((pos = position_count * counter) % 2 != 0)
			pos++;
		if (info[counter]->number == -1)
		{
			pl_number = find_free_number(players_number, info);
			info[counter]->number = pl_number;
		}
		else
			pl_number = info[counter]->number;
		pc = add_pc(pc, pl_number, pos);
		game_info->names[counter] = 0xffffffff - pl_number + 1;
		game_info->last_live = game_info->names[counter];
		counter++;
	}
	return (pc);
}
