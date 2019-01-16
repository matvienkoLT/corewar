/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def_marker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:12:05 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/20 15:12:06 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define BEHOVE 		1
#define NOT_BEHOVE	0

void		marker_add_to_lst(char *name, t_marker_lst **lst)
{
	size_t	len;

	len = ft_strnlen(name, 0x3A);
	if ((*lst)->name)
	{
		(*lst)->next = push_back();
		(*lst) = (*lst)->next;
	}
	(*lst)->name = ft_memcpy(ft_strnew(len), name, len);
	ft_str_del_newline((*lst)->name);
}

static int	check_one_line_data(char *line, t_file *obj)
{
	char	*data;

	if (!(data = ft_del_whitespaces(line)))
		return (EXIT_FAILURE);
	obj->curr_nsymb = data - line;
	if (def_comment(data) == COMMENT || *data == 0xA)
		return (COMMENT);
	if (def_cmmnd(data, obj) == EXIST_CMMNT)
		return (EXIST_CMMNT);
	return (EXIT_FAILURE);
}

static int	char_belongs_to_str(char *ch, char *str_with_cmp)
{
	while (*str_with_cmp)
	{
		if (*ch == *str_with_cmp)
			return (BEHOVE);
		str_with_cmp++;
	}
	return (NOT_BEHOVE);
}

static int	check_after_shield(char *data, t_file *obj)
{
	int status;

	if ((status = check_one_line_data(data, obj)) != EXIT_FAILURE)
	{
		return (EXIST_MARKER);
	}
	return (status);
}

int			def_marker(char *str, t_file *obj)
{
	char	*data;
	int		status;

	data = str;
	while (*data && *data != 0x3A)
	{
		if (!char_belongs_to_str(data, LABEL_CHARS))
		{
			return (IDLENESS);
		}
		data++;
	}
	if (*data == 0x3A)
	{
		marker_add_to_lst(str, &obj->lst_label);
		obj->lst_label->ptr_block = obj->curr_block_size;
		if ((status = check_after_shield(data + 1, obj)) != EXIT_FAILURE)
			return (EXIST_MARKER);
	}
	return (EXIT_FAILURE);
}
