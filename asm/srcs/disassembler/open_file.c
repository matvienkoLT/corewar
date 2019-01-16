/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:46:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/15 16:46:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#define ERROR1	"Error: File %s has too small name\n"
#define ERROR2	"Error: File %s has an invalid header\n"

static char	g_represent[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'};
void	(*g_funx[7])(int fd, t_info *info) =
{
	parse_header, parse_name, parse_null, parse_code_size,
	parse_comment, parse_null, parse_code
};

void	parse_name(int fd, t_info *info)
{
	int		count;
	char	text[1];

	count = 0;
	info->name = ft_strnew(PROG_NAME_LENGTH);
	while (count < PROG_NAME_LENGTH)
	{
		if (!read(fd, &text[0], sizeof(text)))
		{
			ft_print(1, ERROR1, info->name_file);
			exit(1);
		}
		info->name[count++] = text[0];
	}
}

void	parse_header(int fd, t_info *info)
{
	int		count;
	char	head[9];
	char	text[1];

	head[8] = '\0';
	count = 0;
	while (count < MAGIC_HEADER * 2)
	{
		if (!read(fd, &text[0], sizeof(text)))
			break ;
		head[count++] = g_represent[(text[0] >> 4) & 0x0f];
		head[count++] = g_represent[text[0] & 0x0f];
	}
	head[count] = '\0';
	if (info && count == 8 && ft_strcmp(COREWAR_EXEC_MAGIC,
		(const char*)&head) == 0)
		return ;
	else
	{
		ft_print(1, ERROR2, info->name_file);
		exit(1);
	}
}

void	parse_full_file(int fd, t_info *info)
{
	int		parse_counter;

	parse_counter = -1;
	while (++parse_counter < 7)
		g_funx[parse_counter](fd, info);
}

void	ft_file_name(char *name, t_info *info)
{
	char	**bot;
	int		i;

	i = 0;
	bot = ft_strsplit(name, '/');
	while (bot[i] && bot[i + 1] != '\0')
		free(bot[i++]);
	info->name_file = bot[i];
	free(bot);
}

int		open_file(char *name, t_info *info)
{
	int		fd;

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		perror("Open failed on input file");
		return (1);
	}
	ft_file_name(name, info);
	parse_full_file(fd, info);
	ft_asm(info);
	return (0);
}
