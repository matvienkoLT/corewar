/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:36:43 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 16:36:44 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		pc_counter(t_pc *pc)
{
	int		counter;
	t_pc	*pc_cpy;

	counter = 0;
	pc_cpy = pc;
	while (pc_cpy)
	{
		counter++;
		pc_cpy = pc_cpy->next;
	}
	return (counter);
}

void	ft_print_winner(t_game_info *game_info)
{
	int counter;

	counter = 0;
	while (counter != 4)
	{
		if (game_info->last_live == game_info->names[counter])
			break ;
		counter++;
	}
	attron(COLOR_PAIR(8) | A_BOLD);
	mvprintw(PRINT_SIZE_Y - 6, PRINT_START_X_BAR,
			"WINNER - %s", game_info->info[counter]->name);
	mvprintw(PRINT_SIZE_Y - 4, PRINT_START_X_BAR, "Press any key to exit");
	attroff(COLOR_PAIR(8) | A_BOLD);
}

void	ft_print_frame(void)
{
	size_t	i;
	size_t	j;

	attron(COLOR_PAIR(9));
	i = -1;
	while (++i < PRINT_SIZE_Y + 2)
	{
		mvprintw(i, 0, "  ");
		mvprintw(i, PRINT_SIZE_X + 3, "  ");
		mvprintw(i, PRINT_START_X_BAR + 1 + PRINT_SIZE_BAR, "  ");
	}
	j = -1;
	while (++j < PRINT_END_X_BAR + 3)
	{
		mvprintw(0, j, " ");
		mvprintw(PRINT_SIZE_Y + 1, j, " ");
	}
	attroff(COLOR_PAIR(9));
}

void	ft_print_map(t_game_info *game_info, unsigned char *color_map)
{
	size_t			i;
	size_t			j;
	unsigned char	*map;

	map = game_info->field;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			move((i + 1), (j + 1) * 3);
			if (*color_map > 20)
				attron(A_BOLD);
			attron(COLOR_PAIR(*color_map));
			printw("%.2x", *map);
			if (*color_map > 20)
				attroff(A_BOLD);
			attroff(COLOR_PAIR(*color_map));
			map++;
			color_map++;
		}
	}
}
