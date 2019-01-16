/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:46:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/20 15:03:48 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	g_represent[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

int		ft_asm_2(char *chr, char *line, int fd, char *name)
{
	if (!ft_strcmp(chr, "0d"))
		return (ft_lld(line, fd));
	else if (!ft_strcmp(chr, "0e"))
		return (ft_lldi(line, fd));
	else if (!ft_strcmp(chr, "0f"))
		return (ft_lfork(line, fd));
	else if (!ft_strcmp(chr, "10"))
		return (ft_aff(line, fd));
	else
	{
		ft_print(1, "Error: File %s has incorrect code\n", name);
		return (-1);
	}
}

int		ft_asm_1(char *line, char *count, int fd, char *name)
{
	if (!ft_strcmp(line, "02"))
		return (ft_ld(count, fd));
	else if (!ft_strcmp(line, "03"))
		return (ft_st(count, fd));
	else if (!ft_strcmp(line, "04"))
		return (ft_add(count, fd));
	else if (!ft_strcmp(line, "05"))
		return (ft_sub(count, fd));
	else if (!ft_strcmp(line, "06"))
		return (ft_and(count, fd));
	else if (!ft_strcmp(line, "07"))
		return (ft_or(count, fd));
	else if (!ft_strcmp(line, "08"))
		return (ft_xor(count, fd));
	else if (!ft_strcmp(line, "09"))
		return (ft_zjmp(count, fd));
	else if (!ft_strcmp(line, "0a"))
		return (ft_ldi(count, fd));
	else if (!ft_strcmp(line, "0b"))
		return (ft_sti(count, fd));
	else if (!ft_strcmp(line, "0c"))
		return (ft_fork(count, fd));
	else
		return (ft_asm_2(line, count, fd, name));
}

void	ft_asm(t_info *info)
{
	int		count;
	int		fd;
	char	chr[3];
	int		a;

	chr[2] = '\0';
	count = -1;
	fd = ft_create_champion(info);
	ft_print(fd, ".name      \"%s\"\n", info->name);
	ft_print(fd, ".comment   \"%s\"\n\n", info->comment);
	while (info->code[++count])
	{
		chr[0] = g_represent[(info->code[count] >> 4) & 0x0f];
		chr[1] = g_represent[info->code[count] & 0x0f];
		count++;
		if (!ft_strcmp(&chr[0], "01"))
			count += ft_live(&info->code[count], fd);
		else if ((a = ft_asm_1(&chr[0], &info->code[count],
			fd, &info->name_file[0])) != -1)
			count += a;
		else
			break ;
	}
	close(fd);
}
