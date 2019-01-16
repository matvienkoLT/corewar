/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:36:32 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 16:36:34 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_init(void)
{
	initscr();
	curs_set(FALSE);
	noecho();
	start_color();
	init_pair(1, COLOR_GREEN, 0);
	init_pair(11, 0, COLOR_GREEN);
	init_pair(21, COLOR_GREEN, 0);
	init_pair(2, COLOR_BLUE, 0);
	init_pair(12, 0, COLOR_BLUE);
	init_pair(22, COLOR_BLUE, 0);
	init_pair(3, COLOR_RED, 0);
	init_pair(13, 0, COLOR_RED);
	init_pair(23, COLOR_RED, 0);
	init_pair(4, COLOR_CYAN, 0);
	init_pair(14, 0, COLOR_CYAN);
	init_pair(24, COLOR_CYAN, 0);
	init_pair(8, COLOR_WHITE, 0);
	init_pair(9, 0, COLOR_WHITE);
	attron(A_BOLD | COLOR_PAIR(8));
	mvprintw(3, PRINT_START_X_BAR + PRINT_SIZE_BAR / 2 - 4, "COREWAR");
	attroff(A_BOLD | COLOR_PAIR(8));
}

void	ft_print_end(t_game_info *game_info)
{
	ft_print_frame();
	USE(game_info->field);
	ft_print_winner(game_info);
	timeout(-1);
	getch();
	refresh();
	endwin();
	exit(1);
}

int		ft_end_vm(unsigned char *map)
{
	static int num;

	if (map[MEM_SIZE - 1] == 0xff)
	{
		num++;
		if (num == 10)
			return (1);
	}
	return (0);
}

int		ft_infin_visualisation(t_pc **pc, t_game_info *game_info)
{
	char	c;
	size_t	time;

	time = 19;
	while (1)
	{
		timeout(time * 4);
		one_working_cycle(pc, game_info, 0);
		ft_print_data(99 - time, *pc, game_info);
		c = getch();
		if (c == ' ' || c == 's')
			break ;
		else if (c == '-' && time != 98)
			time++;
		else if (c == '+' && time)
			time--;
		if (game_info->end_game)
		{
			ft_print_end(game_info);
			break ;
		}
	}
	return (0);
}

void	ft_visualisation(t_pc *pc, t_game_info *game_info)
{
	char	c;

	ft_print_init();
	ft_print_data(0, pc, game_info);
	while (1)
	{
		c = getch();
		if (c == ' ')
			ft_infin_visualisation(&pc, game_info);
		else if (c == 's')
		{
			one_working_cycle(&pc, game_info, 0);
			ft_print_data(0, pc, game_info);
			if (game_info->end_game)
				ft_print_end(game_info);
		}
	}
}
