/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:54:30 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 18:54:35 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	g_represent[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

void	parse_code(int fd, t_info *info)
{
	int				count;
	unsigned char	text;

	count = 0;
	info->code = (unsigned char *)ft_strnew(info->size_code);
	while (count < info->size_code)
	{
		if (!read(fd, &text, 1))
		{
			ft_print(1, ERROR3, count, info->size_code, info->name);
			exit(1);
		}
		info->code[count++] = text;
	}
	while (read(fd, &text, sizeof(text)))
		count++;
	if (count != info->size_code)
	{
		ft_print(1, ERROR4, count, info->size_code, info->name);
		exit(1);
	}
}

void	parse_comment(int fd, t_info *info)
{
	int		count;
	char	text[1];

	count = 0;
	info->comment = ft_strnew(COMMENT_LENGTH);
	while (count < COMMENT_LENGTH)
	{
		if (!read(fd, &text[0], sizeof(text)))
		{
			ft_print(1, ERROR5, info->name_file);
			exit(1);
		}
		info->comment[count++] = text[0];
	}
}

void	parse_code_size(int fd, t_info *info)
{
	int		count;
	char	text[1];
	char	*size;

	count = 0;
	size = ft_strnew(8);
	while (count < CHAMPION_SIZE * 2)
	{
		if (!read(fd, &text[0], sizeof(text)))
		{
			ft_print(1, ERROR6, info->name_file);
			exit(1);
		}
		size[count++] = g_represent[(text[0] >> 4) & 0x0f];
		size[count++] = g_represent[text[0] & 0x0f];
	}
	info->size_code = ft_atoi_base(size, 16);
	free(size);
	if (info->size_code < 1 || info->size_code > CHAMP_MAX_SIZE)
	{
		ft_print(1, ERROR7, info->size_code, CHAMP_MAX_SIZE, info->name_file);
		exit(1);
	}
}

void	parse_null(int fd, t_info *info)
{
	int		count;
	char	text[1];

	count = 0;
	while (count++ < 4 && info)
		if (!read(fd, &text[0], sizeof(text)) || text[0] != 0)
		{
			printf(ERROR8, info->name_file);
			exit(1);
		}
}
