/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:12:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/19 17:12:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	hextodec(char *hex)
{
	char			ch;
	unsigned int	value;

	value = 0;
	ch = *hex;
	while (1)
	{
		if (ch >= '0' && ch <= '9')
			value = (value << 4) + (ch - '0');
		else if (ch >= 'a' && ch <= 'f')
			value = (value << 4) + (ch - 'a' + 10);
		else
			break ;
		ch = *(++hex);
	}
	return (value);
}

char			*dectobin(int value)
{
	int		k;
	int		counter;
	char	*bin;
	int		b_conter;

	bin = ft_memalloc(9);
	counter = 7;
	b_conter = 0;
	while (counter >= 0)
	{
		k = value >> counter;
		if (k & 1)
			bin[b_conter] = '1';
		else
			bin[b_conter] = '0';
		counter--;
		b_conter++;
	}
	return (bin);
}
