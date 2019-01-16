/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:34:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/27 18:34:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	if_ind(unsigned int param, t_pc *pc,
		t_game_info *game_info)
{
	unsigned short	position;
	int				pos_counter;

	position = (short)param % IDX_MOD;
	pos_counter = pc->position;
	while (position--)
		pos_counter = MAKE_CYCLE(pos_counter);
	return (parse_param(4, game_info, pos_counter, 0));
}

unsigned int		*parse_num(int *arg, unsigned int *params, t_pc *pc,
		t_game_info *game_info)
{
	int				counter;
	unsigned int	*numbers;

	numbers = (unsigned int*)malloc(sizeof(unsigned int) * 2);
	counter = 1;
	while (counter != 3)
	{
		if (arg[counter] == REG_CODE)
			numbers[counter - 1] = pc->reg[params[counter]];
		else if (arg[counter] == DIR_CODE)
			numbers[counter - 1] = params[counter];
		else if (arg[counter] == IND_CODE && counter == 1)
			numbers[counter - 1] = if_ind(params[counter], pc, game_info);
		counter++;
	}
	return (numbers);
}

void				ft_sti(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg)
{
	int				counter;
	unsigned short	edit_pos;
	unsigned char	tmp;
	int				pos_counter;
	unsigned int	*numbers;

	ft_reset_highlighting((unsigned char*)game_info->colors, pc->pl_number);
	numbers = parse_num(arg, params, pc, game_info);
	edit_pos = (((short)numbers[0] + (short)numbers[1]) % IDX_MOD);
	free(numbers);
	counter = 3;
	pos_counter = pc->position;
	while (edit_pos--)
		pos_counter = MAKE_CYCLE(pos_counter);
	while (counter >= 0)
	{
		tmp = (unsigned char)(pc->reg[params[0]] >> counter * 8);
		game_info->field[pos_counter] = tmp;
		game_info->colors[pos_counter] = pc->pl_number;
		pos_counter = MAKE_CYCLE(pos_counter);
		counter--;
	}
	pc->position = game_info->working_pos;
}
