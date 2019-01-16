/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:08:00 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/04 14:08:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -v] [-n] <champion1.cor> <...>\n");
	ft_printf("#### PREFERENCES ###########################################"
		"####################\n");
	ft_printf("-v N  <champion1.cor>  : Make a number for champion \n");
	ft_printf("#### TEXT OUTPUT MODE #######################################"
		"###################\n");
	ft_printf("-d N      : Dumps memory after N cycles then exits\n");
	ft_printf("#### VISUALISATION OUTPUT MODE ##############################"
		"###################\n");
	ft_printf("-v        : Ncurses output mode\n");
	ft_printf("#############################################################"
		"###################\n");
	exit(1);
}

static t_info	*ft_new_info(void)
{
	t_info	*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->name_file = NULL;
	info->name = NULL;
	info->comment = NULL;
	info->code = NULL;
	info->number = -1;
	return (info);
}

int				main(int argc, char **argv)
{
	int			i;
	t_flag_		flag;

	i = -1;
	while (++i < 4)
		flag.info[i] = ft_new_info();
	flag.info[4] = NULL;
	if (argc == 1)
		usage();
	ft_flag_management(argc, argv, &flag);
	start_vm((t_info**)&(flag.info), flag.pl_num, flag.flags);
	return (0);
}
