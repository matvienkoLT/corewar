/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmmnd_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:16:17 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/09 20:16:18 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ullto000_format(size_t *value)
{
	char	*data;
	char	*str;
	int		indent;

	if (*value < 100ULL)
	{
		if (!(data = ft_strnew(3)))
			return (NULL);
		ft_memset(data, 0x30, 3);
		indent = 0x3 - ft_dgt_quntt_i(*value);
		if (!(str = ft_itoa(*value)))
			return (NULL);
		ft_memcpy(data + indent, str, ft_strlen(str));
		free(str);
	}
	else
		data = ft_ulltoa(*value);
	return (data);
}

int			warning_err_mark(size_t nline, char *data, size_t *cmmnd_len)
{
	char *ptr_nline;

	if (!(ptr_nline = ullto000_format(&nline)))
		return (EXIT_FAILURE);
	write(2, "[\e[5m\e[35mWARNING\e[0m] ", 23);
	write(2, "Current marker [", 17);
	write(2, "\e[4m", 5);
	write(2, data, *cmmnd_len);
	write(2, "\e[24m] at line [", 17);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, "] not identified.\n", 18);
	free(ptr_nline);
	return (EXIT_FAILURE);
}

int			cmmnd_name_err(size_t nline, char *data, size_t *cmmnd_len)
{
	char *ptr_nline;

	if (!(ptr_nline = ullto000_format(&nline)))
		return (EXIT_FAILURE);
	ft_str_del_newline(data);
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Current command [", 18);
	write(2, "\e[4m", 5);
	write(2, data, *cmmnd_len);
	write(2, "\e[24m] at line [", 17);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, "] not available at this moment.\n", 32);
	free(ptr_nline);
	return (EXIT_FAILURE);
}

int			cmmnd_argv_err(size_t nline, int argv)
{
	char *ptr_nline;
	char ptr_argv;

	if (!(ptr_nline = ullto000_format(&nline)))
		return (EXIT_FAILURE);
	ptr_argv = argv + '0';
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Corrupted command argv[", 23);
	write(2, &ptr_argv, 1);
	write(2, "]:line [", 8);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, "]\n", 2);
	free(ptr_nline);
	return (EXIT_FAILURE);
}
