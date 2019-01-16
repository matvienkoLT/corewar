/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_generator_tools_scnd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 19:02:00 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/25 19:02:01 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

#define DOT			obj->ptr_buff
#define ARGV_IND	2
#define ARGV_DIR	4
#define ARGV_REG	8
#define CMMN_HEXA	g_option[op->cmmnd_id].cmmnd_hexa
#define CMMND_LAB	g_option[op->cmmnd_id].label_size

int			cmp_argv_type(int fnd_type, int *cmmd_hexa, int *num_argv)
{
	if (fnd_type & g_option[*cmmd_hexa].argv[*num_argv - 1])
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static void	def_size_argv(t_argv *ar, ARV *op, t_file *obj)
{
	char	*ptr_data;
	int		st;

	ptr_data = &(obj->ptr_buff[obj->buff_index]);
	if (ar->typel == ARGV_REG)
		int_to_byte(ar->value, st = T_REG_SIZE, &ptr_data);
	if (ar->typel == ARGV_DIR)
		int_to_byte(ar->value, st = CMMND_LAB, &ptr_data);
	if (ar->typel == ARGV_IND)
		int_to_byte(ar->value, st = T_IND_SIZE, &ptr_data);
	obj->buff_index += st;
}

int			buffering_data(t_file *obj, ARV *op, t_argv *ar)
{
	int		i;
	char	*ptr_code;

	i = 0;
	ptr_code = &obj->ptr_buff[obj->buff_index];
	int_to_byte(CMMN_HEXA, COMMAND_SIZE, &ptr_code);
	obj->buff_index += COMMAND_SIZE;
	if (g_option[op->cmmnd_id].argc > 1)
	{
		int_to_byte(op->cmmnd_argv_size, ARGV_SIZE, &ptr_code);
		obj->buff_index += ARGV_SIZE;
	}
	while (i < op->cmmnd_argc)
	{
		def_size_argv(&ar[i], op, obj);
		i++;
	}
	return (EXIT_SUCCESS);
}
