/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:31:01 by lmatvien          #+#    #+#             */
/*   Updated: 2019/01/10 11:31:02 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ususpected_error(void)
{
	write(2, "[\e[5m\e[31mERROR\e[0m]", 21);
	write(2, " Unsuspected error code. Report about this:\n ", 45);
	write(2, "\t\e[31mlmatvien@student.unit.ua\e[0m\n", 36);
	write(2, "\n", 1);
	return (EXIT_FAILURE);
}

int	undef_instruction_error(void)
{
	write(2, "[\e[5m\e[31mERROR\e[0m]", 21);
	write(2, " Data collection failed. Your file not consist any", 51);
	write(2, " instruction or your data corrupted.\n", 38);
	return (EXIT_FAILURE);
}

int	empty_file(void)
{
	write(2, "[\e[5m\e[31mERROR\e[0m]", 21);
	write(2, " Empty file.\n", 13);
	return (EXIT_FAILURE);
}
