/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:49:29 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/10 20:49:31 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define D_NAME		obj->box.prog_name
#define D_COMMENT	obj->box.comment
#define D_EXE		obj->box.prog_size

static void	success_result(char *data)
{
	write(2, "[\e[5m\e[32mSUCCESS\e[0m]", 23);
	write(2, " Output file name: \e[4m", 24);
	write(2, data, ft_strlen(data));
	write(2, "\e[0m\n", 6);
}

void		int_to_byte(unsigned int value, int size, char **str)
{
	size = (size - 1) * 0x8;
	while (size >= 0)
	{
		**str = (value >> size) & 0xff;
		size -= 0x8;
		(*str)++;
	}
}

static char	*name_preparation(char *data)
{
	char	*ptr_str;
	size_t	len;

	if (!(ptr_str = ft_strrchr(data, 0x2E)))
		return (NULL);
	len = ptr_str - data;
	if (!(ptr_str = ft_strnew(len + 0x4)))
		return (NULL);
	ft_memcpy(ptr_str, data, len);
	ptr_str = ft_strcat(ptr_str, ".cor");
	return (ptr_str);
}

static int	create_file(t_file *obj, char *data, size_t len)
{
	int		fd;
	int		status;
	char	*name;

	if (!(name = name_preparation(obj->file_name)))
		return (EXIT_FAILURE);
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		status = EXIT_FAILURE;
	else
	{
		status = EXIT_SUCCESS;
		write(fd, data, len);
		success_result(name);
	}
	if (data)
		free(data);
	if (name)
		free(name);
	return (status);
}

int			asm_collect_data(t_file *obj)
{
	char	*data;
	char	*ptr_data;
	size_t	len;

	len = MAGIC_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + NULL_SIZE +
		EXE_CODE_SIZE + NULL_SIZE + D_EXE;
	data = ft_strnew(len);
	ptr_data = data;
	int_to_byte(COREWAR_EXEC_MAGIC, MAGIC_SIZE, &(ptr_data));
	ft_memcpy(ptr_data, D_NAME, PROG_NAME_LENGTH);
	ptr_data += PROG_NAME_LENGTH;
	ft_memset(ptr_data, 0x0, (size_t)NULL_SIZE);
	ptr_data += NULL_SIZE;
	int_to_byte(D_EXE, EXE_CODE_SIZE, &ptr_data);
	ft_memcpy(ptr_data, D_COMMENT, COMMENT_LENGTH);
	ptr_data += COMMENT_LENGTH;
	ft_memset(ptr_data, 0x0, (size_t)NULL_SIZE);
	ptr_data += NULL_SIZE;
	ft_memcpy(ptr_data, obj->ptr_buff, D_EXE);
	if (create_file(obj, data, len) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
