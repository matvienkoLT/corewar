/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def_cmmnd_argv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:16:30 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/26 15:16:31 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define ARGV_IND 2
#define ARGV_DIR 4
#define ARGV_REG 8

static int	def_t_reg(char *str, size_t *indent)
{
	int		r_num;
	size_t	pre_save_len;

	pre_save_len = 0;
	if (*str == 'r')
	{
		pre_save_len = ft_atoi_and_qntt_dgt(str + 1, &r_num);
		if (r_num >= 0)
		{
			*indent = pre_save_len + 1;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

int			def_type_cmmnd_argv(char **str)
{
	size_t		indent;
	int			status;
	char		*data;

	indent = 0;
	status = EXIT_FAILURE;
	if (**str == SEPARATOR_CHAR)
		(*str)++;
	if (!(data = ft_del_whitespaces(*str)))
		return (EXIT_FAILURE);
	if (def_t_reg(data, &indent) == EXIT_SUCCESS)
		status = ARGV_REG;
	else if (*data == DIRECT_CHAR)
		status = ARGV_DIR;
	else if (*data == LABEL_CHAR || ft_isdigit(*data) ||
		(*data == 0x2d && ft_isdigit(*(data + 1))))
		status = ARGV_IND;
	if (status == ARGV_DIR || status == ARGV_IND)
		indent = ft_grap_to_whitespaces_or_ch(data + 1, SEPARATOR_CHAR) + 1;
	*str = data + indent;
	return (status);
}

int			add_argv_size(int argv, int *t_dir, int block_size)
{
	if (argv == ARGV_REG)
		block_size += T_REG_SIZE;
	else if (argv == ARGV_DIR)
		block_size += *t_dir;
	else
		block_size += T_IND_SIZE;
	return (block_size);
}
