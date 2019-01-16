/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def_properties_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:43:17 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 18:43:17 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define C_LEN	obj->cmmnd_len
#define BT		byte_wrote

static int	r_until_q_mark_appr(size_t byte_wrote, t_file *obj)
{
	int		st;

	while ((st = read(obj->fd, &obj->box.prog_name[BT], 1)) > 0 &&
		obj->box.prog_name[BT] != 0x22 && BT < PROG_NAME_LENGTH)
	{
		symb_position_calc(&C_NLINE, &C_SYMB, &obj->box.prog_name[BT]);
		BT++;
	}
	if (obj->box.prog_name[BT] == 0x22)
		obj->box.prog_name[BT] = 0x0;
	if (BT > PROG_NAME_LENGTH)
		return (err_to_long_name(PROG_NAME_LENGTH));
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
		ft_memcpy(&obj->box.prog_name, str + 1, len);
		C_SYMB += len + 1;
		if (ft_strnlen(str + 1, 0xA))
			C_NLINE++;
		if (r_until_q_mark_appr(len, obj) == EXIT_FAILURE)
			return (asm_err_end_line(C_NLINE + 1, C_SYMB + 1));
	}
	else
	{
		if (len > PROG_NAME_LENGTH)
			return (err_to_long_name(PROG_NAME_LENGTH));
		C_SYMB += (len + 2);
		ft_memcpy(obj->box.prog_name, str + 1, len);
	}
	return (EXIT_SUCCESS);
}

static int	def_name(char *str, t_file *obj)
{
	if (*str == 0x22)
	{
		if (found_start_q_mark(str, obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (asm_err_b_line(C_NLINE, C_SYMB + 1));
	return (EXIT_SUCCESS);
}

int			def_player_name(char *str, t_file *obj)
{
	char	*data;

	if (!ft_strncmp(NAME_CMD_STRING, str, C_LEN))
	{
		if (!(data = ft_del_whitespaces(str + C_LEN)))
			return (EXIT_FAILURE);
		obj->curr_nsymb += data - str;
		if (*data == 0x0)
			return (asm_err_end_line(C_NLINE + 1, C_SYMB + 1));
		else
		{
			if (def_name(data, obj) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (IDLENESS);
}
