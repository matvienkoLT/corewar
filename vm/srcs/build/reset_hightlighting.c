/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_highlightning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:38:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/24 19:38:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_reset_highlighting(unsigned char *map_color, int player)
{
	size_t counter;

	counter = -1;
	while (++counter < MEM_SIZE)
	{
		if (map_color[counter] == 20 + player)
			map_color[counter] -= 20;
	}
}
