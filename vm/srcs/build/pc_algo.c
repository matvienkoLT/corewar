/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:03:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/19 13:03:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	make_command(t_pc *pc, t_game_info *game_info)
{
	unsigned int	*params;
	int				arg[3];

	ft_bzero(arg, 3 * 4);
	if (pc->command.code)
	{
		game_info->working_pos = pc->position;
		if (pc->command.cobage)
			pc->is_error = parse_arg(pc, arg, game_info);
		params = take_arg(game_info, pc, pc->command, arg);
		starting_launch(pc, params, arg, game_info);
		parse_command1(pc, game_info);
	}
}

void	ft_cycle(t_pc **pc, t_game_info *game_info, int dump)
{
	t_pc		*pc_cpy;
	static int	for_dump;

	if (dump && for_dump == dump - 1)
	{
		game_info->end_game = 1;
		return ;
	}
	pc_cpy = *pc;
	while (pc_cpy)
	{
		if (pc_cpy->cycle_num <= 0)
			parse_command(pc_cpy, game_info);
		if (--pc_cpy->cycle_num <= 0)
		{
			make_command(pc_cpy, game_info);
		}
		pc_cpy = pc_cpy->next;
	}
	for_dump++;
}

int		one_working_cycle(t_pc **pc, t_game_info *game_info, int dump)
{
	static int	cycle_counter;

	dump = 0;
	cycle_counter++;
	ft_cycle(pc, game_info, dump);
	if (game_info->cycle_to_die <= 0)
	{
		game_info->end_game = 1;
		return (0);
	}
	if (cycle_counter > 0 && cycle_counter == game_info->cycle_to_die)
	{
		make_check(game_info, pc);
		if (game_info->end_game)
			return (0);
		cycle_counter = 0;
	}
	if (!game_info->max_checks)
	{
		game_info->max_checks = MAX_CHECKS;
		game_info->cycle_to_die -= CYCLE_DELTA;
	}
	return (1);
}

void	ft_print_dump_data(t_game_info *game_info)
{
	int i;
	int	counter;

	counter = 0;
	while (counter < MEM_SIZE)
	{
		ft_printf("%#.4x :", counter);
		i = 64;
		while (i--)
			ft_printf(" %.2x", game_info->field[counter++]);
		ft_printf("\n");
	}
}

void	pc_algo(t_pc *pc, t_game_info *game_info, int dump)
{
	while (1)
	{
		one_working_cycle(&pc, game_info, dump);
		if (game_info->end_game)
			break ;
	}
	print_winner(game_info, pc);
	if (dump)
		ft_print_dump_data(game_info);
}
