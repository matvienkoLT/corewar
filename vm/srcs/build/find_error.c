/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:41:00 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/03 12:41:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		try_to_find(t_command command, int *args, int counter)
{
	int c_counter;

	c_counter = 0;
	while (c_counter != 3)
	{
		if (args[counter] == command.cargs[counter][c_counter])
			return (1);
		c_counter++;
	}
	return (0);
}

int		find_error(t_command command, int *args)
{
	int counter;
	int find;
	int error;

	counter = 0;
	error = 0;
	while (counter != command.arg_num)
	{
		if (args[counter] == -1)
			error++;
		find = try_to_find(command, args, counter);
		if (error == command.arg_num)
		{
			ft_bzero(args, 3 * 4);
			return (1);
		}
		if (find == 0)
			return (1);
		counter++;
	}
	return (0);
}
