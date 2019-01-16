/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:50:05 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/03 15:50:06 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define UN unsigned int

static int	ft_dgt_quntt(UN n, UN base)
{
	int quantt;

	if (n == 0)
		return (1);
	quantt = 0;
	while (n > 0)
	{
		n /= base;
		quantt++;
	}
	return (quantt);
}

static char	*ft_cr_string(size_t size, UN n, UN base)
{
	int		index;
	int		pre_state;
	char	*s;

	if (!(s = ft_strnew(sizeof(char) * size)))
		return (NULL);
	index = size;
	while (n > 0)
	{
		if ((pre_state = n % base) > 9)
			s[--index] = pre_state + 87;
		else
			s[--index] = pre_state + '0';
		n /= base;
	}
	return (s);
}

char		*ft_uitoa_base(UN n, UN base)
{
	char	*ptr_n;
	size_t	size;

	if (base <= 1)
		return (NULL);
	size = ft_dgt_quntt(n, base);
	ptr_n = ft_cr_string(size, n, base);
	return (ptr_n);
}
