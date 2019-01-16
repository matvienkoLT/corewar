/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def_properties_comment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:18:30 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/19 15:18:31 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define CMMNT_LEM obj->cmmnt_len

int			def_comment(char *str)
{
	char *data;

	data = str;
	if (*data == 0xA || *data == 0x0 || *data == COMMENT_CHAR ||
		*data == ALTERNATIVE_COM_CHAR)
		return (COMMENT);
	return (IDLENESS);
}

static int	r_until_q_mark_appr(size_t byte_wrote, t_file *obj)
{
	int st;

	while ((st = read(obj->fd, &obj->box.comment[BT], 1)) > 0 &&
		obj->box.comment[BT] != 0x22 && BT < COMMENT_LENGTH)
	{
		symb_position_calc(&C_NLINE, &C_SYMB, &obj->box.comment[BT]);
		BT++;
	}
	if (obj->box.comment[BT] == 0x22)
		obj->box.comment[BT] = 0x0;
	if (BT > COMMENT_LENGTH)
	{
		return (err_text_comment(COMMENT_LENGTH));
	}
	if (st <= 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	found_start_q_mark(char *str, t_file *obj)
{
	size_t len;

	if (!(len = ft_strnlen(str + 1, 0x22)) && (*(str + 1)) != 0x22)
	{
		len = ft_strlen(str + 1);
		ft_memcpy(&obj->box.comment, str + 1, len);
		C_SYMB += len + 1;
		if (ft_strnlen(str + 1, 0xA))
			C_NLINE++;
		if (r_until_q_mark_appr(len, obj) == EXIT_FAILURE)
			return (asm_err_end_line(C_NLINE + 1, C_SYMB + 1));
	}
	else
	{
		if (len > COMMENT_LENGTH)
			return (err_text_comment(COMMENT_LENGTH));
		C_SYMB += (len + 2);
		ft_memcpy(obj->box.comment, str + 1, len);
	}
	return (EXIT_SUCCESS);
}

static int	def_comment_body(char *str, t_file *obj)
{
	if (*str == 0x22)
	{
		if (found_start_q_mark(str, obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (asm_err_end_line(C_NLINE + 1, C_SYMB + 1));
	return (EXIT_SUCCESS);
}

int			def_main_comment(char *str, t_file *obj)
{
	char	*data;

	if (!ft_strncmp(COMMENT_CMD_STRING, str, CMMNT_LEM))
	{
		if (!(data = ft_del_whitespaces(str + CMMNT_LEM)))
			return (EXIT_FAILURE);
		obj->curr_nsymb += data - str;
		if (*data == 0x0)
			return (asm_err_end_line(C_NLINE + 1, C_SYMB + 1));
		else
		{
			if (def_comment_body(data, obj) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (IDLENESS);
}
