/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:55:30 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 18:55:40 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_sub(char *line, int fd)
{
	int count;

	ft_print(fd, "	sub	");
	count = params(line, 0, fd, 3);
	return (count);
}

int		ft_and(char *line, int fd)
{
	int count;

	ft_print(fd, "	and	");
	count = params(line, 0, fd, 3);
	return (count);
}

int		ft_or(char *line, int fd)
{
	int count;

	ft_print(fd, "	or	");
	count = params(line, 4, fd, 3);
	return (count);
}

int		ft_xor(char *line, int fd)
{
	int count;

	ft_print(fd, "	xor	");
	count = params(line, 4, fd, 3);
	return (count);
}

int		ft_zjmp(char *line, int fd)
{
	int par_dex;

	par_dex = ft_two_b_from_three(line);
	ft_print(fd, "	zjmp	%%%d\n", par_dex);
	return (1);
}
