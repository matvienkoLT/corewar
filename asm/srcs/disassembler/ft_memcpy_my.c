/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_my.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:08:54 by vickovtu          #+#    #+#             */
/*   Updated: 2019/01/12 17:09:26 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	*ft_memcpy_my(void *dst, const void *src, size_t n)
{
	size_t			i;
	size_t			*dst64;
	size_t			*src64;
	unsigned char	*dst8;
	unsigned char	*src8;

	src64 = (size_t *)src;
	dst64 = (size_t *)dst;
	i = n / sizeof(size_t);
	while (i--)
		*dst64++ = *src64++;
	src8 = (unsigned char *)src64;
	dst8 = (unsigned char *)dst64;
	i = n % sizeof(size_t);
	while (i--)
		*dst8++ = *src8++;
	return (dst);
}
