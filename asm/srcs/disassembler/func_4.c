/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:56:36 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 18:56:53 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_ldi(char *line, int fd)
{
	int count;

	ft_print(fd, "	ldi	");
	count = params(line, 2, fd, 3);
	return (count);
}

int		ft_sti(char *line, int fd)
{
	int count;

	ft_print(fd, "	sti	");
	count = params(line, 2, fd, 3);
	return (count);
}

int		ft_fork(char *line, int fd)
{
	int par_dex;

	par_dex = ft_two_b_from_three(line);
	ft_print(fd, "	fork	%%%d \n", par_dex);
	return (1);
}

int		ft_lld(char *line, int fd)
{
	int count;

	count = params(line, 4, fd, 2);
	ft_print(fd, "	lld	");
	return (count);
}

int		ft_lldi(char *line, int fd)
{
	int count;

	ft_print(1, "	lldi	");
	count = params(line, 4, fd, 3);
	return (count);
}
