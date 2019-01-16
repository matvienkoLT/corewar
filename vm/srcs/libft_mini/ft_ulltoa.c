/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:21:57 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/10 12:21:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#define ULLI unsigned long long int

static ULLI	ft_dgt_quntt(ULLI n)
{
	ULLI	quantt;

	if (n == 0ULL)
		return (1);
	quantt = 0ULL;
	while (n > 0)
	{
		n /= 10;
		quantt++;
	}
	return (quantt);
}

static void	ft_cr_string(char *s, size_t size, ULLI n)
{
	ULLI	index;

	index = size - 1;
	if (n == 0)
		s[0] = '0';
	s[index] = '\0';
	while (n > 0)
	{
		s[--index] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_ulltoa(size_t n)
{
	char			*ptr_n;
	size_t			size;

	if (n == SIZE_MAX)
		return (ft_strcat(ft_strnew(21), "18446744073709551615"));
	size = ft_dgt_quntt(n) + 1;
	ptr_n = (char *)malloc(sizeof(char) * size);
	if (!ptr_n)
		return (NULL);
	ft_cr_string(ptr_n, size, n);
	return (ptr_n);
}
