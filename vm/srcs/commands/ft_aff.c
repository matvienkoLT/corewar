/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:45:00 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/03 11:45:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_aff(unsigned int *params, t_pc *pc, t_game_info *game_info, int *arg)
{
	char	symbol;

	arg = NULL;
	symbol = (params[0] % 256);
	ft_putchar(symbol);
	pc->position = game_info->working_pos;
}
