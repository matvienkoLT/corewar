/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def_properties_cmmnd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:42:37 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/24 13:42:38 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

t_option g_option[OP_ARR_SIZE] = {
	{"live", 1, {T_DIR}, 0x1, 4, "alive"},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 0x2, 4, "load"},
	{"st", 2, {T_REG, T_IND | T_REG}, 0x3, 4, "store"},
	{"add", 3, {T_REG, T_REG, T_REG}, 0x4, 4, "addition"},
	{"sub", 3, {T_REG, T_REG, T_REG}, 0x5, 4, "soustraction"},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		0x6, 4, "et (and  r1, r2, r3   r1&r2 -> r3"},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		0x7, 4, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		0x8, 4, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
	{"zjmp", 1, {T_DIR}, 0x9, 2, "jump if zero"},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		0xA, 2, "load index"},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		0xB, 2, "store index"},
	{"fork", 1, {T_DIR}, 0xC, 2, "fork"},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 0xD, 4, "long load"},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		0xE, 2, "long load index"},
	{"lfork", 1, {T_DIR}, 0xF, 2, "long fork"},
	{"aff", 1, {T_REG}, 0x10, 4, "aff"},
	{0, 0, {0}, 0, 0, 0}};

int			def_cmnd_init_size(int asm_cmmnd_id, int *t_dir)
{
	int size;

	size = 1;
	if (g_option[asm_cmmnd_id].argc > 1)
		size += 1;
	*t_dir = g_option[asm_cmmnd_id].label_size;
	return (size);
}

static int	waste_or_not_enough_data(char *data, int asm_cmmnd_id, int num_argv)
{
	if (num_argv < g_option[asm_cmmnd_id].argc)
		return (EXIT_FAILURE);
	if (!(data = ft_del_whitespaces(data)) || (*data != COMMENT_CHAR &&
		*data != ALTERNATIVE_COM_CHAR && *data != 0xA && *data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	def_cmmnd_size(char *str, int cmmnd_id, int *bk_size, t_file *obj)
{
	char	*data;
	int		num_argv;
	int		t_dir;
	int		status;

	*bk_size = def_cmnd_init_size(cmmnd_id, &t_dir);
	num_argv = 0;
	data = str;
	while (num_argv < g_option[cmmnd_id].argc)
	{
		if (!(data = ft_del_whitespaces(data)))
			return (EXIT_FAILURE);
		if (num_argv > 0 && num_argv < g_option[cmmnd_id].argc &&
			*data != SEPARATOR_CHAR)
			break ;
		if ((status = def_type_cmmnd_argv(&data)) == EXIT_FAILURE)
			return (cmmnd_argv_err(obj->curr_nline, num_argv + 1));
		else
			*bk_size = add_argv_size(status, &t_dir, *bk_size);
		num_argv++;
	}
	if (waste_or_not_enough_data(data, cmmnd_id, num_argv) == EXIT_FAILURE)
		return (err_undef_data(obj->curr_nline, ft_del_whitespaces(data)));
	return (EXIT_SUCCESS);
}

static int	def_type_cmmnd(char *str, int *block_size, t_file *obj)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_grap_to_whitespaces_or_ch(str, DIRECT_CHAR);
	while (i < OP_ARR_SIZE - 1)
	{
		if (!ft_strncmp(str, g_option[i].name, len))
			return (def_cmmnd_size(str + len, i, block_size, obj));
		i++;
	}
	return (cmmnd_name_err(obj->curr_nline, str, &len));
}

int			def_cmmnd(char *line, t_file *obj)
{
	int	block_size;

	if (def_type_cmmnd(line, &block_size, obj) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	obj->curr_block_size += block_size;
	return (EXIST_CMMNT);
}
