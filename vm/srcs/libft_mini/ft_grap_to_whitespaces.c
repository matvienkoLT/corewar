/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grap_to_whitespaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:17:01 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/26 19:17:02 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_grap_to_whitespaces(char *str)
{
	char	*data;

	if (!str)
		return (0);
	data = str;
	while ((*data != 0x20 && *data != 0x9 &&
		*data != 0xB && *data != 0xD) &&
		*data != '\0')
		data++;
	return (data - str);
}
