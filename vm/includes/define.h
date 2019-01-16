/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:59:53 by amurakho          #+#    #+#             */
/*   Updated: 2019/01/13 17:00:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_DEFINE_H
# define PROJECT_DEFINE_H
# define MEM_SIZE				(4*1024)
# define REG_NUMBER				16
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define IND_SIZE				2
# define REG_SIZE				1
# define DIR_SIZE				4
# define CARRY(x, y) 			((x) ? (y = 0) : (y = 1))
# define REG_SIZE_MEM			4
# define MAGIC_HEADER			4
# define COREWAR_EXEC_MAGIC		"00ea83f3"
# define IDX_MOD				(MEM_SIZE / 8)
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define PROG_NAME_LENGTH		128
# define CHAMPION_SIZE			4
# define CHAMP_MAX_SIZE			682
# define COMMENT_LENGTH			2048
# define PRINT_SIZE_Y			64
# define PRINT_SIZE_X			PRINT_SIZE_Y * 3
# define PRINT_START_X_BAR		PRINT_SIZE_X + 6
# define PRINT_SIZE_BAR			60
# define PRINT_END_X_BAR		PRINT_START_X_BAR + PRINT_SIZE_BAR
# define USE(x) 				(void)x
# define MAKE_CYCLE(x)			((x + 1) == (MEM_SIZE) ? 0 : x + 1)
# define ERROR1	"Error: File %s has too small name\n"
# define ERROR2	"Error: File %s has an invalid header\n"
# define ERROR3	"%d bytes < %d bytes! Error: Champion %s has too small a code\n"
# define ERROR4	"%d bytes > %d bytes! Error: Champion %s has too large a code\n"
# define ERROR5	"Error: File %s has too small comment\n"
# define ERROR6	"Error: File %s has incorrect size a code\n"
# define ERROR7	"%d bytes > %d bytes! Error: File %s has too large a code\n"
# define ERROR8	"Error: File %s has size differ from what its header says\n"

#endif
