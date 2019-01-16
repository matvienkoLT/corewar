/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:45:32 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 16:46:44 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#define ERROR3	"%d bytes < %d bytes! Error: Champion %s has too small a code\n"
#define ERROR4	"%d bytes > %d bytes! Error: Champion %s has too large a code\n"
#define ERROR5	"Error: File %s has too small comment\n"
#define ERROR6	"Error: File %s has incorrect size a code\n"
#define ERROR7	"%d bytes > %d bytes! Error: File %s has too large a code\n"
#define ERROR8	"Error: File %s has size differ from what its header says\n"

static char	g_represent[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};

void	parse_code(int fd, t_info *info)
{
	int				count;
	unsigned char	text;

	count = 0;
	info->code = ft_strnew(info->size_code);
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
