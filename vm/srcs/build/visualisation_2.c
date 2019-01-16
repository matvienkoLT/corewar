/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:36:37 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 16:36:40 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_players(int player_number,
		int *position, t_game_info *game_info)
{
	int	i;

	attroff(A_BOLD | COLOR_PAIR(8));
	i = -1;
	while (++i < player_number)
	{
		attron(COLOR_PAIR(i + 1) | A_BOLD);
		*position += 2;
		mvprintw(*position, PRINT_START_X_BAR, "Player %d : %s",
			(int)game_info->names[i], game_info->info[i]->name);
		attroff(COLOR_PAIR(i + 1) | A_BOLD);
	}
	attron(A_BOLD | COLOR_PAIR(8));
}

void	ft_print_bar_data(size_t speed, t_game_info *game_info, t_pc *pc)
{
	int				position;
	static size_t	i;

	attron(A_BOLD | COLOR_PAIR(8));
	position = 5;
	mvprintw(position, PRINT_START_X_BAR, "Speed = %-5d", speed);
	position += 2;
	mvprintw(position, PRINT_START_X_BAR, "Cycle = %-5d", i++);
	position += 2;
	mvprintw(position, PRINT_START_X_BAR, "Processes = %-5d", pc_counter(pc));
	ft_print_players(game_info->vis_num, &position, game_info);
	position += 2;
	mvprintw(position, PRINT_START_X_BAR, "CYCLE_TO_DIE : %-5d",
			game_info->cycle_to_die);
	position += 2;
	mvprintw(position, PRINT_START_X_BAR, "CYCLE_DELTA : %-5d", CYCLE_DELTA);
	position += 2;
	mvprintw(position, PRINT_START_X_BAR, "NBR_LIVE : %-5d", NBR_LIVE);
	position += 2;
	mvprintw(position, PRINT_START_X_BAR, "MAX_CHECKS : %-5d", MAX_CHECKS);
	attroff(A_BOLD | COLOR_PAIR(8));
}

void	ft_free_cell(t_pc *pc, int counter, t_game_info *game_info)
{
	t_pc	*pc_cpy;
	int		is_free;

	is_free = 1;
	pc_cpy = pc;
	while (pc_cpy)
	{
		if (pc_cpy->position == counter)
		{
			is_free = 0;
			break ;
		}
		pc_cpy = pc_cpy->next;
	}
	if (is_free)
	{
		if (game_info->colors[counter] > 10)
			game_info->colors[counter] -= 10;
		else if (game_info->colors[counter] == 9)
			game_info->colors[counter] = 0;
	}
}

void	ft_make_color_map(t_game_info *game_info, t_pc *pc)
{
	int		counter;
	t_pc	*pc_cpy;

	counter = 0;
	while (counter != MEM_SIZE)
	{
		pc_cpy = pc;
		while (pc_cpy)
		{
			if (counter == pc_cpy->position && game_info->colors[counter] != 0)
			{
				if (game_info->colors[counter] < 10)
					game_info->colors[counter] += 10;
				else if (game_info->colors[counter] > 20)
					game_info->colors[counter] -= 10;
			}
			else if (game_info->colors[counter] == 0 &&
			counter == pc_cpy->position)
				game_info->colors[counter] = 9;
			else if (game_info->colors[counter] < 20)
				ft_free_cell(pc, counter, game_info);
			pc_cpy = pc_cpy->next;
		}
		counter++;
	}
}

void	ft_print_data(size_t speed, t_pc *pc, t_game_info *game_info)
{
	ft_make_color_map(game_info, pc);
	ft_print_frame();
	ft_print_map(game_info, (unsigned char*)game_info->colors);
	ft_print_bar_data(speed, game_info, pc);
	refresh();
	move(0, 0);
}
