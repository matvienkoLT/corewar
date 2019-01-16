/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_generator_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:18:25 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/27 17:18:26 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define ARGV_IND			2
#define ARGV_DIR			4
#define ARGV_REG			8
#define LS_M_N				obj->lst_label->name
#define CMMND_L_S			g_option[op->cmmnd_id].label_size
#define BLOCK_SZ			obj->curr_block_size
#define LABEL_MEM_PTR		obj->lst_label->ptr_block
#define CURR_S				op ->curr_cmmnd_size

static int		def_t_reg(char **str, t_argv_param *op, t_argv *value)
{
	int		r_num;
	int		indent;
	size_t	pre_save_len;

	pre_save_len = 0;
	if (**str == 'r')
	{
		pre_save_len = ft_atoi_and_qntt_dgt((*str + 1), &r_num);
		if (r_num >= 0 && r_num <= T_REG_MAX_VALUE)
		{
			indent = pre_save_len + 1;
			*str = (*str) + indent;
			value->value = r_num;
			if (def_trush_after_argv(*str, op) == EXIT_SUCCESS)
				return (cmp_argv_type(T_REG, &op->cmmnd_id, &op->curr_argv));
		}
	}
	return (EXIT_FAILURE);
}

static int		cmp_marker(char **data, t_file *obj, t_argv *value, int typel)
{
	size_t	len;

	obj->lst_label = obj->lst_head;
	if (!(*(++(*data))) || !obj->lst_label->name)
	{
		len = ft_grap_to_whitespaces_or_ch(*data, SEPARATOR_CHAR);
		return (warning_err_mark(obj->curr_nline, *data, &len));
	}
	len = ft_grap_to_whitespaces_or_ch(*data, SEPARATOR_CHAR);
	while (obj->lst_label && LS_M_N)
	{
		if (!ft_strncmp(*data, LS_M_N, len) && !*(LS_M_N + len))
		{
			value->value = typel + (int)LABEL_MEM_PTR - (int)BLOCK_SZ;
			*data = (*data) + len;
			return (EXIT_SUCCESS);
		}
		obj->lst_label = obj->lst_label->next;
	}
	return (warning_err_mark(obj->curr_nline, *data, &len));
}

static int		def_t_dir(char **str, T_ARGV_P *op, t_file *obj, t_argv *value)
{
	char	*data;

	data = *str;
	if (*data == DIRECT_CHAR)
	{
		if (*(++(data)) == LABEL_CHAR)
		{
			if (cmp_marker(&data, obj, value, CURR_S) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (ft_isdigit(*data) ||
			(*data == 0x2d && ft_isdigit(*(data + 1))))
		{
			value->value = signed_hexa(ft_atoi(data), CMMND_L_S, &(data));
			data += ft_grap_to_whitespaces_or_ch(data, SEPARATOR_CHAR);
			if (def_trush_after_argv(data, op) == EXIT_FAILURE)
				return (err_undef_data(obj->curr_nline, data));
		}
		else
			return (EXIT_FAILURE);
		*str = data;
		return (cmp_argv_type(T_DIR, &op->cmmnd_id, &op->curr_argv));
	}
	return (EXIT_FAILURE);
}

static int		def_t_ind(char **str, T_ARGV_P *op, t_file *obj, t_argv *value)
{
	char	*data;
	int		status;

	data = *str;
	status = EXIT_FAILURE;
	if (*data == LABEL_CHAR)
	{
		if (cmp_marker(&data, obj, value, CURR_S) == EXIT_SUCCESS)
			status = cmp_argv_type(T_IND, &op->cmmnd_id, &op->curr_argv);
	}
	else if (ft_isdigit(*data) || (*data == 0x2d && ft_isdigit(*(data + 1))))
	{
		value->value = signed_hexa(ft_atoi(data), T_IND_SIZE, &(data));
		data += ft_grap_to_whitespaces_or_ch(data, SEPARATOR_CHAR);
		status = cmp_argv_type(T_IND, &op->cmmnd_id, &op->curr_argv);
	}
	else
		return (EXIT_FAILURE);
	*str = data;
	return (status);
}

int				argv_val(char **str, t_file *obj, t_argv_param *op, t_argv *val)
{
	int		status;
	char	*data;

	status = EXIT_FAILURE;
	if (**str == SEPARATOR_CHAR)
		(*str)++;
	if (!(data = ft_del_whitespaces(*str)))
		return (EXIT_FAILURE);
	if (def_t_reg(&data, op, val) == EXIT_SUCCESS)
		status = ARGV_REG;
	else if (def_t_dir(&data, op, obj, val) == EXIT_SUCCESS)
		status = ARGV_DIR;
	else if (def_t_ind(&data, op, obj, val) == EXIT_SUCCESS)
		status = ARGV_IND;
	val->typel = status;
	*str = data;
	return (status);
}
