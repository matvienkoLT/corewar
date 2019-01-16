/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:40:31 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 18:40:32 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_p(t_pc *pointer)
{
	t_pc *tmp;

	tmp = pointer->next;
	pointer->next = pointer->next->next;
	free(tmp);
}

void			del_player(t_pc **pc, unsigned int player_num)
{
	t_pc *pointer;

	while (1)
	{
		pointer = *pc;
		if (pointer == NULL)
			return ;
		if (pointer->reg[1] == player_num)
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
		if (pointer->reg[1] == player_num)
			ft_p(pointer);
		else
			pointer = pointer->next;
	}
}
