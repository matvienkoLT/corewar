/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grap_to_whitespaces_or_char.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:23:27 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/10 12:23:34 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_grap_to_whitespaces_or_ch(char *str, int ch)
{
	char	*data;
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	data = str;
	while ((*data != 0x20 && *data != 0x9 &&
			*data != 0xB && *data != 0xD &&
			*data != ch) && *data++ != '\0')
		len++;
	return (len);
}
