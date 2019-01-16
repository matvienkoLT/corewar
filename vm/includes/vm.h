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
# include <ncurses.h>
# include "define.h"
# include "ft_printf.h"

typedef struct			s_command
{
	char				*code;
	int					arg_num;
	int					cargs[3][3];
	int					cycle_num;
	int					is_recarry;
	int					label_size;
	int					cobage;
}						t_command;

typedef struct			s_pc
{
	int					position;
	int					carry;
	unsigned int		reg[REG_NUMBER + 1];
	int					is_alive;
	t_command			command;
	int					cycle_num;
	int					args[3];
	int					is_error;
	struct s_pc			*next;
	int					pl_number;
}						t_pc;

typedef struct			s_info
{
	char				*name_file;
	char				*name;
	char				*comment;
	int					size_code;
	unsigned char		*code;
	int					number;
}						t_info;

typedef struct			s_game_info
{
	unsigned char		field[MEM_SIZE];
	int					players_num;
	int					cycle_to_die;
	int					max_checks;
	int					live[4];
	unsigned int		last_live;
	int					working_pos;
	unsigned int		names[4];
	int					dump;
	int					end_game;
	char				colors[MEM_SIZE];
	int					live_count;
	int					vis_num;
	t_info				**info;
}						t_game_info;

typedef struct			s_flag_
{
	int					pl_num;
	int					flags[2];
	t_info				*info[5];
}						t_flag_;

void					make_field(t_game_info *game_info, t_info **info,
		t_pc *pc);
t_pc					*pc_init(int players_number, t_info **info,
		t_game_info *game_info);
unsigned int			hextodec(char *hex);
void					parse_command(t_pc *pc, t_game_info *game_info);
int						starting_launch(t_pc *pc, unsigned int *params,
		int *arg, t_game_info *game_info);
int						parse_arg(t_pc *pc, int *args, t_game_info *game_info);
unsigned int			*take_arg(t_game_info *game_info, t_pc *pc,
		t_command command, int *args);
void					make_check(t_game_info *game_info, t_pc	**pc);
t_pc					*add_pc(t_pc *start_pc, unsigned int player_num,
		int pos);
int						make_cycle(int pos, int edit_num);
void					del_pc(t_pc *pc, unsigned int player_num);
void					ft_st(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_live(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_ld(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_sti(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_add(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_sub(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_and(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_or(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_xor(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_zjmp(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_ldi(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_fork(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_lld(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_lldi(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_lfork(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
void					ft_aff(unsigned int *params, t_pc *pc,
		t_game_info *game_info, int *arg);
char					*dectobin(int value);
unsigned int			parse_param(int size, t_game_info *game_info,
		int pos, int flag);
int						find_error(t_command command, int *args);
void					pc_algo(t_pc *pc, t_game_info *game_info, int dump);
int						open_file(char *name, t_info *info);
void					start_vm(t_info **info, int players_num, int *flags);
void					ft_visualisation(t_pc *pc, t_game_info *game_info);
int						one_working_cycle(t_pc **pc_cpy,
						t_game_info *game_info, int dump);
void					copy_pc(t_pc *start_pc);
void					ft_reset_highlighting(unsigned char *map_color,
						int player);
void					free_mem(t_game_info *game_info);
void					print_winner(t_game_info *game_info, t_pc *pc);
void					ft_print_players(int player_number,
						int *position, t_game_info *game_info);
void					ft_print_bar_data(size_t speed,
						t_game_info *game_info, t_pc *pc);
void					ft_free_cell(t_pc *pc, int counter,
						t_game_info *game_info);
void					ft_make_color_map(t_game_info *game_info, t_pc *pc);
void					ft_print_data(size_t speed, t_pc *pc,
						t_game_info *game_info);
int						pc_counter(t_pc *pc);
void					ft_print_winner(t_game_info *game_info);
void					ft_print_frame(void);
void					ft_print_map(t_game_info *game_info,
						unsigned char *color_map);
void					ft_flag_management(int argc, char **argv,
						t_flag_ *flag);
void					usage(void);
void					del_player(t_pc **pc, unsigned int player_num);
int						ft_print(int fd, const char *format, ...);
void					parse_code(int fd, t_info *info);
void					parse_comment(int fd, t_info *info);
void					parse_code_size(int fd, t_info *info);
void					parse_null(int fd, t_info *info);
void					parse_header(int fd, t_info *info);
void					parse_name(int fd, t_info *info);
void					*ft_memcpy_my(void *dst, const void *src, size_t n);
void					parse_command1(t_pc *pc, t_game_info *game);

#endif
