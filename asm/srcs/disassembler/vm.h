/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <amurakho@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:46:00 by amurakho          #+#    #+#             */
/*   Updated: 2018/12/15 16:46:00 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE			100
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define MAGIC_HEADER		4
# define CHAMPION_SIZE		4
# define CHAMP_MAX_SIZE		682
# define COREWAR_EXEC_MAGIC		"00ea83f3"

typedef struct		s_info
{
	char			*name_file;
	char			*name;
	char			*comment;
	int				size_code;
	char			*code;
}					t_info;

int					ft_print(int fd, const char *format, ...);
int					ft_asm_2(char *chr, char *line, int fd, char *name);
int					ft_asm_1(char *line, char *count, int fd, char *name);
void				ft_asm(t_info *info);
int					ft_lfork(char *line, int fd);
int					ft_aff(char *line, int fd);
int					ft_create_champion(t_info *info);
int					ft_sub(char *line, int fd);
int					ft_and(char *line, int fd);
int					ft_or(char *line, int fd);
int					ft_xor(char *line, int fd);
int					ft_zjmp(char *line, int fd);
char				*ft_bin_1(char c);
char				*ft_bin(char c);
char				*ft_subtr(char *line);
int					ft_t(char *line, int dir);
int					params(char *line, int dir, int fd, int par);
int					ft_ldi(char *line, int fd);
int					ft_sti(char *line, int fd);
int					ft_fork(char *line, int fd);
int					ft_lld(char *line, int fd);
int					ft_lldi(char *line, int fd);
int					ft_two_b_from_three(char *line);
int					ft_live(char *line, int fd);
int					ft_ld(char *line, int fd);
int					ft_st(char *line, int fd);
int					ft_add(char *line, int fd);
void				parse_code(int fd, t_info *info);
void				parse_comment(int fd, t_info *info);
void				parse_code_size(int fd, t_info *info);
void				parse_null(int fd, t_info *info);
int					open_file(char *name, t_info *info);
void				ft_file_name(char *name, t_info *info);
void				parse_header(int fd, t_info *info);
void				parse_name(int fd, t_info *info);
void				*ft_memcpy_my(void *dst, const void *src, size_t n);
int					ft_atoi_base(char *str, int base);

#endif
