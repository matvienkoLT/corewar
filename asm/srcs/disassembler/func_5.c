/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:57:36 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 18:57:47 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_lfork(char *line, int fd)
{
	int par_dex;

	par_dex = ft_two_b_from_three(line);
	ft_print(fd, "	lfork	%%%d \n", par_dex);
	return (1);
}

int		ft_aff(char *line, int fd)
{
	int count;

	count = params(line, 0, fd, 1);
	ft_print(fd, "	aff	");
	return (count);
}

int		ft_create_champion(t_info *info)
{
	char	**arr;
	char	*name;
	int		i;
	int		fd;

	arr = ft_strsplit(info->name_file, '.');
	name = ft_strjoin(arr[0], ".s");
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Error: File %s has not create\n", name);
		exit(1);
	}
	free(name);
	return (fd);
}

char	*ft_subtr(char *line)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	str = ft_strnew(8);
	while (i < 4)
		str[i++] = 'f';
	count = 0;
	while (line[count])
		str[i++] = line[count++];
	str[i] = '\0';
	free(line);
	return (str);
}
