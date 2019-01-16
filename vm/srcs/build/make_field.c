/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:36:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/19 13:36:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	make_field(t_game_info *game_info, t_info **info, t_pc *pc)
{
	int		p_counter;
	size_t	counter;
	int		pos;
	size_t	code_len;
	char	hex[3];

	ft_bzero(hex, 3);
	p_counter = 0;
	while (p_counter != game_info->players_num)
	{
		counter = 0;
		pos = pc->position;
		code_len = info[p_counter]->size_code - 1;
		while (counter <= code_len)
		{
			game_info->field[pos] = info[p_counter]->code[counter];
			game_info->colors[pos] = p_counter + 1;
			pos++;
			counter++;
		}
		pc = pc->next;
		p_counter++;
	}
}
