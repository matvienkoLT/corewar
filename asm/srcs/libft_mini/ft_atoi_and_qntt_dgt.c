/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_and_qntt_dgt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:44:13 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/14 20:44:14 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX 922337203685477580
#define INIT value = 0; len = 0

static int		double_sign(char *argv)
{
	if ((*argv != '+' && *argv != '-') && (*argv < 48 || *argv > 57))
		return (1);
	argv++;
	if ((*argv < 48 || *argv > 57) && *argv != '\0')
		return (1);
	return (0);
}

static int		minus_indicator(char *argv)
{
	int minus;

	if (*argv == '-')
	{
		minus = -1;
		argv++;
	}
	else
		minus = 1;
	return (minus);
}

static char		*space_symbols(char *argv, int *minus)
{
	while ((*argv >= 9 && *argv <= 13) || *argv == 32)
		argv++;
	*minus = minus_indicator(argv);
	return (argv);
}

size_t			ft_atoi_and_qntt_dgt(char *argv, int *ptr_num)
{
	long long int	value;
	int				minus;
	size_t			len;

	INIT;
	argv = space_symbols(argv, &minus);
	if ((*argv < 48 || *argv > 57) && double_sign(argv))
		return (0);
	while (*argv != '\0')
	{
		if (minus < 0 && (value > MAX || (value == MAX && *argv > '7')))
			return (0);
		else if (value > MAX || (value == MAX && *argv > '7'))
			return (-1);
		if (*argv >= 48 && *argv <= 57)
		{
			value = value * 10 + (*argv - '0');
			len++;
			if (*(argv + 1) < 48 || *(argv + 1) > 57)
				break ;
		}
		argv++;
	}
	*ptr_num = value * minus;
	return (len);
}
