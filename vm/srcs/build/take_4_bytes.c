/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_4_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:38:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/24 19:38:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int		parse_four(t_game_info *game_info, int pos_plus)
{
	int				counter;
	char			str[5];
	unsigned int	number;

	ft_bzero(str, 5);
	counter = 0;
	while (counter != 4)
	{
		str[counter] = game_info->field[game_info->working_pos +
			pos_plus + counter];
		counter++;
	}
	number = hextodec(str);
	return (number);
}
