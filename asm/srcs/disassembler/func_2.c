/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:54:03 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 18:54:20 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	g_represent[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

int		ft_two_b_from_three(char *line)
{
	char	*parameter;
	int		count;
	int		i;
	int		par_dex;

	count = 0;
	i = -1;
	parameter = ft_strnew(4);
	while (++i < 2)
	{
		parameter[count++] = g_represent[(line[i] >> 4) & 0x0f];
		parameter[count++] = g_represent[line[i] & 0x0f];
	}
	parameter[count] = '\0';
	parameter = (parameter[0] == 'f') ? ft_subtr(parameter) : parameter;
	par_dex = ft_atoi_base(parameter, 16);
	free(parameter);
	return (par_dex);
}

int		ft_live(char *line, int fd)
{
	char	parameter[9];
	int		count;
	int		i;
	int		par_dex;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		parameter[count++] = g_represent[(line[i] >> 4) & 0x0f];
		parameter[count++] = g_represent[line[i] & 0x0f];
	}
	parameter[count] = '\0';
	par_dex = ft_atoi_base(&parameter[0], 16);
	ft_print(fd, "	live	%%%d\n", par_dex);
	return (3);
}

int		ft_ld(char *line, int fd)
{
	int count;

	ft_print(fd, "	ld	");
	count = params(line, 4, fd, 2);
	return (count);
}

int		ft_st(char *line, int fd)
{
	int count;

	ft_print(fd, "	st	");
	count = params(line, 0, fd, 2);
	return (count);
}

int		ft_add(char *line, int fd)
{
	int count;

	ft_print(fd, "	add	");
	count = params(line, 0, fd, 3);
	return (count);
}
