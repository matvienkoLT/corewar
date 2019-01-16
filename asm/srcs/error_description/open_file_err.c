/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:17:01 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 12:17:02 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	asm_usage(void)
{
	write(2, "Usage: ./asm [-a] <sourcefile.s>\n", 33);
}

void	fopen_error(char *file_name)
{
	write(2, "Can't read source file ", 23);
	write(2, file_name, ft_strlen(file_name));
	write(2, "\n", 1);
}

int		new_line_error(void)
{
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Not found new line at the end of file.\n", 40);
	return (EXIT_FAILURE);
}
