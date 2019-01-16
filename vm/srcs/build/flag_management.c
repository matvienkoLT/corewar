/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:32:38 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 20:26:06 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_flag_n(int argc, char **argv, t_flag_ *flag, int *i)
{
	if (++(*i) < argc)
	{
		if (argv[*i][0] >= '1' && argv[*i][0] <= '4')
		{
			flag->info[flag->pl_num]->number = ft_atoi(argv[*i]);
			if (flag->info[flag->pl_num]->number < 1)
				usage();
			if (flag->info[flag->pl_num]->number > 4)
				usage();
		}
		else
			usage();
	}
	else
		usage();
}

void	ft_flag_file(char **argv, t_flag_ *flag, int *i)
{
	if (flag->pl_num == 4)
		usage();
	if (open_file(argv[*i], flag->info[flag->pl_num]))
		exit(1);
	flag->pl_num++;
}

void	ft_flag_dump(int argc, char **argv, t_flag_ *flag, int *i)
{
	if (++(*i) < argc)
	{
		if (argv[*i][0] >= '0' && argv[*i][0] <= '9')
			flag->flags[1] = ft_atoi(argv[*i]);
		else
			usage();
	}
	else
		usage();
}

void	ft_flag_management(int argc, char **argv, t_flag_ *flag)
{
	int		i;

	ft_bzero(flag->flags, 2 * 4);
	flag->pl_num = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-v"))
			flag->flags[0] = 1;
		else if (ft_strequ(argv[i], "-dump"))
			ft_flag_dump(argc, argv, flag, &i);
		else if (ft_strequ(argv[i], "-n"))
			ft_flag_n(argc, argv, flag, &i);
		else
			ft_flag_file(argv, flag, &i);
	}
	if (flag->pl_num == 0)
		usage();
}
