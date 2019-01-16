/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:53:42 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/12 20:53:45 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_info	*ft_new_info(void)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	info->name_file = NULL;
	info->name = NULL;
	info->comment = NULL;
	info->code = NULL;
	return (info);
}

int				open_dissassembler(char *argv)
{
	t_info *info;

	info = ft_new_info();
	return (open_file(argv, info) == EXIT_FAILURE);
}
