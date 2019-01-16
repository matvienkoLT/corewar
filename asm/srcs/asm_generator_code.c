/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_generator_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 19:02:00 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/25 19:02:01 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"
#define START		obj->ptr_to_start_code
#define INREASE		obj->curr_block_size++; op.curr_cmmnd_size++

#define ARGV_IND 2
#define ARGV_DIR 4
#define ARGV_REG 8

int			def_type_argv(char **data, t_file *obj, T_ARGV_P *op, t_argv *val)
{
	int	status;

	if ((status = argv_val(data, obj, op, val)) == ARGV_REG)
	{
		op->curr_cmmnd_size += T_REG_SIZE;
		obj->curr_block_size += T_REG_SIZE;
		op->cmmnd_argv_size |= (REG_CODE << (8 - op->curr_argv * 0x2));
	}
	else if (status == ARGV_DIR)
	{
		op->curr_cmmnd_size += g_option[op->cmmnd_id].label_size;
		obj->curr_block_size += g_option[op->cmmnd_id].label_size;
		op->cmmnd_argv_size |= (DIR_CODE << (8 - op->curr_argv * 0x2));
	}
	else if (status == ARGV_IND)
	{
		op->curr_cmmnd_size += T_IND_SIZE;
		obj->curr_block_size += T_IND_SIZE;
		op->cmmnd_argv_size |= (IND_CODE << (8 - op->curr_argv * 0x2));
	}
	else
		status = cmmnd_argv_err(obj->curr_nline, op->curr_argv + 1);
	return (status);
}

static int	def_marker_command(char *line, t_file *obj)
{
	size_t	len;
	char	*data;

	len = ft_grap_to_whitespaces_or_ch(line, LABEL_CHAR);
	if (!(data = ft_del_whitespaces(line + len)))
		return (EXIT_FAILURE);
	if (*data == LABEL_CHAR)
	{
		if ((data = ft_del_whitespaces(data + 1)) && (*data != 0x0 &&
			*data != 0xA && *data != COMMENT_CHAR &&
			*data != ALTERNATIVE_COM_CHAR))
		{
			if (grap_cmmnd(data, obj) == EXIST_CMMNT)
				return (EXIST_CMMNT);
			else
				return (EXIT_FAILURE);
		}
		else
			return (EXIST_MARKER);
	}
	return (EXIT_FAILURE);
}

static int	analyzing_init_data(char *line, t_file *obj)
{
	int		status;
	char	*data;

	status = EXIT_FAILURE;
	if (!(data = ft_del_whitespaces(line)))
		return (EXIT_FAILURE);
	ft_str_del_newline(data);
	if (def_comment(data) == COMMENT)
		status = COMMENT;
	else if ((status = def_marker_command(data, obj)) == EXIST_CMMNT ||
		status == EXIST_MARKER)
		status = EXIST_MARKER;
	else if (grap_cmmnd(data, obj) == EXIST_CMMNT)
		status = EXIST_CMMNT;
	free(line);
	return (status);
}

int			asm_code_generate(t_file *obj)
{
	char	*curr_line;
	int		status;
	int		nline;

	if ((lseek(obj->fd, START, SEEK_SET)) < 0)
		return (undef_instruction_error());
	obj->curr_nline = obj->nline_code_start;
	obj->curr_nsymb = 0ULL;
	obj->curr_block_size = 0ULL;
	obj->ptr_buff = (char *)malloc(obj->box.prog_size + 1);
	obj->ptr_buff[obj->box.prog_size] = 0;
	while (get_next_line(obj->fd, &curr_line))
	{
		if (!ft_strchr(curr_line, 0xA))
			nline = 0;
		else
			nline = 1;
		if ((status = analyzing_init_data(curr_line, obj)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (!nline && (status == EXIST_CMMNT || status == EXIST_MARKER))
			return (new_line_error());
		obj->curr_nline++;
	}
	return (EXIT_SUCCESS);
}
