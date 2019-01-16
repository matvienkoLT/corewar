/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 09:34:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/25 09:34:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	make_cycle(int pos, int edit_num)
{
	while (edit_num)
	{
		if (pos++ == MEM_SIZE * 2)
			pos = 0;
		edit_num--;
	}
	return (pos);
}
