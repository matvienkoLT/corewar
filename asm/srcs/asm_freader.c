/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_freader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:59:18 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 17:59:19 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define NAME_ERROR		obj->name_status
#define COMMENT_ERROR	obj->cmmnt_status

static int	def_marker_or_cmmnd(char *line, t_file *obj)
{
	int	status;

	status = EXIT_SUCCESS;
	if ((status = def_marker(line, obj)) == EXIST_MARKER)
		return (EXIST_MARKER);
	else if ((status = def_cmmnd(line, obj)) == EXIST_CMMNT)
		return (EXIST_CMMNT);
	else
	{
		if (def_player_name(line, obj) == EXIT_SUCCESS)
			asm_double_name_err(obj->curr_nline, 1);
		else if (def_main_comment(line, obj) == EXIT_SUCCESS)
			asm_double_comment_err(obj->curr_nline, 1);
		status = EXIT_FAILURE;
	}
	return (status);
}

static int	def_start_executed_code(char *data, t_file *obj)
{
	if ((obj->ptr_to_start_code = lseek(obj->fd, 0, SEEK_CUR)) < 0)
		return (ususpected_error());
	obj->ptr_to_start_code -= (int)(ft_strlen(data));
	obj->nline_code_start = obj->curr_nline;
	return (EXIT_SUCCESS);
}

static int	analyzing_init_data(char *line, t_file *obj)
{
	char	*data;
	int		status;

	if (!(data = ft_del_whitespaces(line)))
		return (EXIT_FAILURE);
	obj->curr_nsymb = data - line;
	if (def_comment(data) == COMMENT)
		status = COMMENT;
	else if (!NAME_ERROR && !COMMENT_ERROR)
		status = def_marker_or_cmmnd(data, obj);
	else if (def_player_name(data, obj) == EXIT_SUCCESS)
		status = --NAME_ERROR;
	else if (def_main_comment(data, obj) == EXIT_SUCCESS)
		status = --COMMENT_ERROR;
	else
		status = undef_instruction_error();
	if ((status == EXIST_CMMNT || status == EXIST_MARKER)
		&& obj->ptr_to_start_code < 0)
		status = def_start_executed_code(line, obj);
	free(line);
	return (status);
}

int			srch_frst_cmmnd(t_file *obj)
{
	char	*curr_line;

	while (get_next_line(obj->fd, &curr_line))
	{
		obj->curr_nline++;
		if (analyzing_init_data(curr_line, obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (!obj->curr_nline)
		return (empty_file());
	obj->box.prog_size = obj->curr_block_size;
	if (asm_code_generate(obj) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
