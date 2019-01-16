/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_generator_tools_thr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:37:38 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/10 20:37:43 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define C_ARGV		op.curr_argv
#define INREASE		obj->curr_block_size++; op.curr_cmmnd_size++

static int	cmmd_reference(char *line, int cmmnd_id, t_file *obj)
{
	char			*data;
	t_argv_param	op;
	t_argv			av[g_option[cmmnd_id].argc];

	op.curr_argv = 1;
	op.cmmnd_argc = g_option[cmmnd_id].argc;
	op.cmmnd_id = cmmnd_id;
	op.cmmnd_argv_size = 0x0;
	data = line;
	obj->curr_block_size++;
	op.curr_cmmnd_size = 1;
	if (op.cmmnd_argc > 1)
	{
		INREASE;
	}
	while (C_ARGV <= op.cmmnd_argc)
	{
		if (!(data = ft_del_whitespaces(data)))
			return (EXIT_FAILURE);
		if (def_type_argv(&data, obj, &op, &av[C_ARGV - 1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		C_ARGV++;
	}
	buffering_data(obj, &op, &av[0]);
	return (EXIST_CMMNT);
}

int			grap_cmmnd(char *line, t_file *obj)
{
	size_t i;
	size_t len;

	i = 0;
	if (!(line = ft_del_whitespaces(line)))
		return (EXIT_FAILURE);
	len = ft_grap_to_whitespaces_or_ch(line, DIRECT_CHAR);
	while (i < OP_ARR_SIZE - 1)
	{
		if (!ft_strncmp(line, g_option[i].name, len))
			return (cmmd_reference(line + len, i, obj));
		i++;
	}
	return (EXIT_FAILURE);
}

int			def_trush_after_argv(char *str, t_argv_param *op)
{
	char *data;

	if (!(data = ft_del_whitespaces(str)))
		return (EXIT_FAILURE);
	if (op->cmmnd_argc > 1 && op->curr_argv < op->cmmnd_argc)
	{
		if (*data != SEPARATOR_CHAR)
			return (EXIT_FAILURE);
	}
	else if (op->cmmnd_argc == 1 || op->curr_argv == op->cmmnd_argc)
	{
		if (*data != COMMENT_CHAR && *data != ALTERNATIVE_COM_CHAR &&
			*data != 0xA && !*data && *data)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			signed_hexa(int value, int size, char **data)
{
	int	i;

	i = 0;
	if (value < 0)
	{
		value *= (-1);
		if (size == sizeof(uint32_t))
			value = ~value + 1;
		else
		{
			size *= 0x8;
			while (i < size)
			{
				value ^= (1 << i);
				i++;
			}
			value++;
		}
		*data = (*data + 1);
	}
	return (value);
}
