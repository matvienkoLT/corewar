/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_data_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:21:15 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/10 10:21:16 by lmatvien         ###   ########.fr       */
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

int			err_undef_data(size_t nline, char *trush)
{
	char *ptr_nline;

	if (!(ptr_nline = ullto000_format(&nline)))
		return (EXIT_FAILURE);
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Undefined data is available as a command argument in ", 53);
	write(2, "line:[", 7);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, "] \"", 4);
	ft_str_del_newline(trush);
	write(2, trush, ft_strlen(trush));
	write(2, "\"\n", 2);
	free(ptr_nline);
	return (EXIT_FAILURE);
}
