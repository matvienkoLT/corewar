/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintain_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:16:13 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/19 13:16:14 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		symb_position_calc(size_t *nline, size_t *symb, char *c)
{
	if (*c == 0xA)
	{
		*symb = 0ULL;
		(*nline)++;
	}
	else
		(*symb)++;
}

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

int			asm_err_end_line(size_t nline, size_t symb)
{
	char	*ptr_nline;
	char	*ptr_symb;

	if (!(ptr_nline = ullto000_format(&nline)) ||
		!(ptr_symb = ullto000_format(&symb)))
		return (EXIT_FAILURE);
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Syntax error at token [TOKEN][", 30);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, ":", 1);
	write(2, ptr_symb, ft_strlen(ptr_symb));
	write(2, "] END \"(null)\" \n", 16);
	free(ptr_nline);
	free(ptr_symb);
	return (EXIT_FAILURE);
}

int			asm_err_b_line(size_t nline, size_t symb)
{
	char *ptr_nline;
	char *ptr_symb;

	if (!(ptr_nline = ullto000_format(&nline)) ||
		!(ptr_symb = ullto000_format(&symb)))
		return (EXIT_FAILURE);
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Syntax error at name. Not found opening symbol.[", 48);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, ":", 1);
	write(2, ptr_symb, ft_strlen(ptr_symb));
	write(2, "]\n", 2);
	free(ptr_nline);
	free(ptr_symb);
	return (EXIT_FAILURE);
}

void		asm_lexical_err(size_t nline, size_t symb)
{
	char *ptr_nline;
	char *ptr_symb;

	if (!(ptr_nline = ullto000_format(&nline)) ||
		!(ptr_symb = ullto000_format(&symb)))
		return ;
	write(2, "[\e[5m\e[31mERROR\e[0m] ", 22);
	write(2, "Lexical error at [", 18);
	write(2, ptr_nline, ft_strlen(ptr_nline));
	write(2, ":", 2);
	write(2, ptr_symb, ft_strlen(ptr_symb));
	write(2, "]\n", 2);
	free(ptr_nline);
	free(ptr_symb);
}
