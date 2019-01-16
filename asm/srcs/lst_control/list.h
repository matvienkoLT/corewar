/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:59:09 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/20 15:59:09 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct			s_marker_lst
{
	char				*name;
	size_t				ptr_block;
	struct s_marker_lst	*next;
}						t_marker_lst;

void					create_lst(t_marker_lst **head);
t_marker_lst			*push_back(void);
#endif
