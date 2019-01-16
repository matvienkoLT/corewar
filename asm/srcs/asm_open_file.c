/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:47:18 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 14:48:11 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"
#include "disasm_interpreter.h"

static int	def_file_exist(char *file_name, int *fd)
{
	if ((*fd = open(file_name, O_RDONLY)) > 0)
	{
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int			def_t_fileype_destination(char *argv, t_file *obj)
{
	char	*str;

	if ((str = ft_strstr(argv, ".s")) && !ft_strcmp(str, ".s")
		&& !def_file_exist(argv, &obj->fd))
	{
		obj->file_name = argv;
		if (srch_frst_cmmnd(obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		asm_collect_data(obj);
		return (EXIT_SUCCESS);
	}
	else if (open_dissassembler(argv) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		fopen_error(argv);
	return (EXIT_FAILURE);
}
