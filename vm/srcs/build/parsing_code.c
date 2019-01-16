/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:06:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/19 11:06:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_command		g_commands[17] =
{
	{"01", 1, {{2, 0, 0}}, 10, 0, 4, 0},
	{"02", 2, {{2, 3, 0}, {1, 0, 0}}, 5, 1, 4, 1},
	{"03", 2, {{1, 0, 0}, {1, 3, 0}}, 5, 0, 4, 1},
	{"04", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 10, 1, 4, 1},
	{"05", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 10, 1, 4, 1},
	{"06", 3, {{1, 2, 3}, {1, 2, 3}, {1, 0, 0}}, 6, 1, 4, 1},
	{"07", 3, {{1, 2, 3}, {1, 2, 3}, {1, 0, 0}}, 6, 1, 4, 1},
	{"08", 3, {{1, 2, 3}, {1, 2, 3}, {1, 0, 0}}, 6, 1, 4, 1},
	{"09", 1, {{2, 0, 0}}, 20, 0, 2, 0},
	{"0a", 3, {{1, 2, 3}, {1, 2, 0}, {1, 0, 0}}, 25, 0, 2, 1},
	{"0b", 3, {{1, 0, 0}, {1, 2, 3}, {1, 2, 0}}, 25, 0, 2, 1},
	{"0c", 1, {{1, 0, 0}}, 800, 0, 2, 0},
	{"0d", 2, {{2, 3, 0}, {1, 0, 0}}, 10, 1, 4, 1},
	{"0e", 3, {{1, 2, 3}, {1, 2, 0}, {1, 0, 0}}, 50, 1, 2, 1},
	{"0f", 1, {{2, 0, 0}}, 1000, 0, 2, 0},
	{"10", 1, {{1, 0, 0}}, 2, 0, 4, 1}};

int				parse_arg(t_pc *pc, int *args, t_game_info *game_info)
{
	char	*b;
	int		arg_counter;
	int		error;

	game_info->working_pos = MAKE_CYCLE(game_info->working_pos);
	b = dectobin(game_info->field[game_info->working_pos]);
	arg_counter = 0;
	while (arg_counter != pc->command.arg_num)
	{
		if (b[arg_counter * 2] == '0' && b[arg_counter * 2 + 1] == '1')
			args[arg_counter] = REG_CODE;
		else if (b[arg_counter * 2] == '1' && b[arg_counter * 2 + 1] == '0')
			args[arg_counter] = DIR_CODE;
		else if (b[arg_counter * 2] == '1' && b[arg_counter * 2 + 1] == '1')
			args[arg_counter] = IND_CODE;
		else
			args[arg_counter] = -1;
		arg_counter += 1;
	}
	game_info->working_pos = MAKE_CYCLE(game_info->working_pos);
	ft_strdel(&b);
	error = find_error(pc->command, args);
	return (error);
}

unsigned int	parse_param(int size, t_game_info *game_info,
int pos, int flag)
{
	unsigned int	number;
	int				shift_counter;

	number = 0;
	shift_counter = 8 * (size - 1);
	while (size)
	{
		number = (((game_info->field[pos])) & 255) << shift_counter | number;
		pos = MAKE_CYCLE(pos);
		if (flag)
			game_info->working_pos = MAKE_CYCLE(game_info->working_pos);
		size--;
		shift_counter -= 8;
	}
	return (number);
}

unsigned int	*take_arg(t_game_info *game, t_pc *pc,
t_command com, int *args)
{
	int				c;
	unsigned int	*p;

	p = (unsigned int *)malloc(sizeof(unsigned int) * com.arg_num);
	ft_bzero(p, com.arg_num * 4);
	c = -1;
	while (++c != com.arg_num)
	{
		if (args[c] == 1)
		{
			p[c] = parse_param(REG_SIZE, game, game->working_pos, 1);
			if (p[c] < 0x1 || p[c] > 0x10)
				pc->is_error = 1;
		}
		else if (args[c] == 2)
			p[c] = parse_param(com.label_size, game, game->working_pos, 1);
		else if (args[c] == 3)
			p[c] = parse_param(IND_SIZE, game, game->working_pos, 1);
		else if (pc->command.arg_num == 1 && pc->command.cobage == 0)
		{
			game->working_pos = MAKE_CYCLE(game->working_pos);
			p[c] = parse_param(com.label_size, game, game->working_pos, 1);
		}
	}
	return (p);
}

void			parse_command1(t_pc *pc, t_game_info *game)
{
	if (game->field[pc->position] <= 0x10 && game->field[pc->position] >= 0x1)
	{
		pc->command = g_commands[game->field[pc->position] - 1];
		pc->cycle_num = g_commands[game->field[pc->position] - 1].cycle_num;
	}
}

void			parse_command(t_pc *pc, t_game_info *game)
{
	if (game->field[pc->position] <= 0x10 && game->field[pc->position] >= 0x1)
	{
		pc->command = g_commands[game->field[pc->position] - 1];
		pc->cycle_num = g_commands[game->field[pc->position] - 1].cycle_num;
	}
	else
	{
		pc->command.code = NULL;
		pc->cycle_num = 0;
		pc->position = MAKE_CYCLE(pc->position);
	}
}
