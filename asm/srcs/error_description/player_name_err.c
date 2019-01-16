/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_name_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:01:07 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/18 18:01:08 by lmatvien         ###   ########.fr       */
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

int			err_to_long_name(size_t lenght)
{
	char	*len;

	len = ft_ulltoa(lenght);
	write(2, "Champion name too long (Max length ", 35);
	write(2, len, ft_strlen(len));
	write(2, ")\n", 2);
	free(len);
	return (EXIT_FAILURE);
}

void		asm_double_name_err(size_t nline, size_t symb)
{
	char *ptr_nline;
	char *ptr_symb;

	if (!(ptr_nline = ullto000_format(&nline)) ||
		!(ptr_symb = ullto000_format(&symb)))
		return ;
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Champion name duplicate at line [", 34);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, ":", 2);
	write(2, ptr_symb, ft_strlen(ptr_symb));
	write(2, "]\n", 2);
	free(ptr_nline);
	free(ptr_symb);
}
