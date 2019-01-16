/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:51:59 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 18:52:54 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define INREASE str[0] = ln[i++]; str[1] = ln[i++]
#define FT_BIN 	ft_bin(g_represent[line[0] & 0x0f])

static char g_represent[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

char		*ft_bin_1(char c)
{
	if (c == 'a' || c == 'A')
		return ("1010");
	if (c == 'b' || c == 'B')
		return ("1011");
	if (c == 'c' || c == 'C')
		return ("1100");
	if (c == 'd' || c == 'D')
		return ("1101");
	if (c == 'e' || c == 'E')
		return ("1110");
	if (c == 'f' || c == 'F')
		return ("1111");
	return ("0000");
}

char		*ft_bin(char c)
{
	if (c == '1')
		return ("0001");
	if (c == '2')
		return ("0010");
	if (c == '3')
		return ("0011");
	if (c == '4')
		return ("0100");
	if (c == '5')
		return ("0101");
	if (c == '6')
		return ("0110");
	if (c == '7')
		return ("0111");
	if (c == '8')
		return ("1000");
	if (c == '9')
		return ("1001");
	return (ft_bin_1(c));
}

int			ft_t(char *line, int dir)
{
	char	*parameter;
	int		count;
	int		i;
	int		par_dex;

	count = 0;
	i = -1;
	parameter = ft_strnew(dir * 2);
	while (++i < dir)
	{
		parameter[count++] = g_represent[(line[i] >> 4) & 0x0f];
		parameter[count++] = g_represent[line[i] & 0x0f];
	}
	parameter[count] = '\0';
	if (dir == 2)
		parameter = (parameter[0] == 'f') ? ft_subtr(parameter) : parameter;
	par_dex = ft_atoi_base(parameter, 16);
	free(parameter);
	return (par_dex);
}

static void	init_par(char *str_last, int *i, int *count)
{
	*str_last = '\0';
	*i = 0;
	*count = 0;
}

int			params(char *line, int dir, int fd, int par)
{
	char	*ln;
	char	str[3];
	int		i;
	int		count;

	init_par(&str[2], &i, &count);
	ln = ft_strjoin(ft_bin(g_represent[(line[0] >> 4) & 0x0f]), FT_BIN);
	while (i < par * 2)
	{
		INREASE;
		if (!ft_strcmp(str, "10"))
		{
			ft_print(fd, "%%%d", ft_t(&line[1 + count], dir));
			count += dir;
		}
		else if (!ft_strcmp(str, "11") && (count += 2))
			ft_print(fd, "%d", ft_t(&line[count - 1], 2));
		else if (!ft_strcmp(str, "01") && (count += 1))
			ft_print(fd, "r%d", ft_t(&line[count], 1));
		if (i < par * 2)
			ft_print(fd, ",");
	}
	ft_print(fd, "\n");
	free(ln);
	return (count);
}
