/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:55:51 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 11:55:52 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_interpreter.h"

static void	init_data(t_file *obj)
{
	create_lst(&obj->lst_label);
	obj->lst_head = obj->lst_label;
	ft_memset(obj->box.prog_name, 0x0, PROG_NAME_LENGTH);
	ft_memset(obj->box.comment, 0x0, COMMENT_LENGTH);
	obj->cmmnd_len = ft_strlen(NAME_CMD_STRING);
	obj->cmmnt_len = ft_strlen(COMMENT_CMD_STRING);
	obj->curr_nline = 0ULL;
	obj->curr_nsymb = 0ULL;
	obj->buff_index = 0ULL;
	obj->curr_block_size = 0ULL;
	obj->ptr_buff = NULL;
	obj->file_name = NULL;
	obj->name_status = 1;
	obj->cmmnt_status = 1;
	obj->ptr_to_start_code = -1;
}

int			main(int argc, char **argv)
{
	t_file obj;

	init_data(&obj);
	if (argc < 0x2)
		asm_usage();
	else
	{
		if (def_t_fileype_destination(argv[argc - 1], &obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
