/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:31:03 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/20 15:31:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void			create_lst(t_marker_lst **head)
{
	*head = (t_marker_lst*)malloc(sizeof(t_marker_lst));
	(*head)->name = NULL;
	(*head)->ptr_block = 0;
	(*head)->next = NULL;
}

t_marker_lst	*push_back(void)
{
	t_marker_lst	*new_element;

	new_element = (t_marker_lst*)malloc(sizeof(t_marker_lst));
	new_element->name = NULL;
	new_element->ptr_block = 0;
	new_element->next = NULL;
	return (new_element);
}
