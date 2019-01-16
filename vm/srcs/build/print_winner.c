/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:38:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/24 19:38:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_winner(t_game_info *game_info, t_pc *pc)
{
	t_pc	*pc_cpy;
	int		counter;

	pc_cpy = pc;
	counter = 0;
	ft_printf("Introducing contestants...\n");
	while (counter != game_info->vis_num)
	{
		ft_printf("* Player 1, weighing %d bytes, \"%s\" (\"%s\") !\n",
		game_info->info[counter]->size_code,
		game_info->info[counter]->name, game_info->info[counter]->comment);
		counter++;
	}
	counter = 0;
	while (counter != 4)
	{
		if (game_info->last_live == game_info->names[counter])
		{
			ft_printf("Contestant %d \"%s\", has won !\n", counter + 1,
			game_info->info[counter]->name);
		}
		counter++;
	}
}
