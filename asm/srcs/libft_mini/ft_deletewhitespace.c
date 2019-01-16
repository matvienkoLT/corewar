/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletewhitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:20:27 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 18:20:29 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void*)0)

char	*ft_del_whitespaces(char *str)
{
	char	*data;

	if (!str)
		return (NULL);
	data = str;
	while ((*data == 0x20 || *data == 0x9 ||
		*data == 0xB || *data == 0xD) && *data != '\0')
		data++;
	return (data);
}
