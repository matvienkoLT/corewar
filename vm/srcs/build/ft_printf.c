/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vickovtu <vickovtu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:46:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/20 15:03:48 by vickovtu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdarg.h>
#include <stddef.h>
#define BUF_SIZE 2056
#define CCH		const char

static void		ft_itoa_my_uns(char *str, size_t *len, size_t v, size_t base)
{
	char const	str_base[] = "0123456789";
	size_t		value_len;
	size_t		len_buf;
	size_t		value_buf;

	value_buf = v;
	value_len = 1;
	while (value_buf > base - 1)
	{
		value_buf /= base;
		value_len++;
	}
	*len += value_len;
	len_buf = *len;
	while (value_len--)
	{
		str[--len_buf] = str_base[v % base];
		v /= base;
	}
}

static void		ft_itoa_my(char *str, size_t *len, ptrdiff_t value, int base)
{
	char const	str_base[] = "0123456789";
	size_t		value_len;
	size_t		len_buf;
	ptrdiff_t	value_buf;

	if (value < 0)
	{
		value = -value;
		str[(*len)++] = '-';
	}
	value_buf = value;
	value_len = 1;
	while (value_buf > base - 1)
	{
		value_buf /= base;
		value_len++;
	}
	*len += value_len;
	len_buf = *len;
	while (value_len--)
	{
		str[--len_buf] = str_base[value % base];
		value /= base;
	}
}

static void		ft_cp_str(char *buf, char *src, size_t len, size_t *full_len)
{
	ft_memcpy_my(buf + *full_len, src, len);
	*full_len += len;
}

static void		ft_search_percent(CCH *f, va_list ap, char *buf, size_t *len)
{
	char	*pointer;
	char	*percent;
	char	*str;

	pointer = (char *)f;
	while ((percent = ft_strchr(pointer, '%')))
	{
		ft_cp_str(buf, pointer, percent - pointer, len);
		++percent;
		if (*percent == 's')
		{
			str = va_arg(ap, char *);
			ft_cp_str(buf, str, ft_strlen(str), len);
		}
		else if (*percent == 'd')
			ft_itoa_my(buf, len, va_arg(ap, int), 10);
		else if (*percent == 'u')
			ft_itoa_my_uns(buf, len, va_arg(ap, unsigned), 10);
		else if (*percent == 'U')
			ft_itoa_my_uns(buf, len, va_arg(ap, size_t), 10);
		else if (*percent == '%')
			buf[(*len)++] = '%';
		pointer = percent + 1;
	}
	ft_cp_str(buf, pointer, ft_strlen(pointer), len);
}

int				ft_print(int fd, const char *format, ...)
{
	va_list	argptr;
	char	buf[BUF_SIZE];
	size_t	len;

	va_start(argptr, format);
	len = 0;
	ft_search_percent(format, argptr, buf, &len);
	write(fd, buf, len);
	va_end(argptr);
	return (len);
}
