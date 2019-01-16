/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_interpreter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <lmatvien@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:01:06 by lmatvien          #+#    #+#             */
/*   Updated: 2018/12/17 12:01:08 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_INTERPRETER_H
# define ASM_INTERPRETER_H

# define T_ARGV_P 			t_argv_param
# define OP_ARR_SIZE		17
# define C_SYMB				obj->curr_nsymb
# define C_NLINE			obj->curr_nline
# define BT					byte_wrote
# define ARV				t_argv_param
# define T_REG_MAX_VALUE	99
# define IDLENESS			6
# define COMMENT			5
# define EXIST_NAME			4
# define EXIST_CMMNT 		3
# define EXIST_MARKER		2
# define T_REG_SIZE			0x1
# define T_IND_SIZE			0x2
# define MAGIC_SIZE			0x4
# define NULL_SIZE			0x4
# define EXE_CODE_SIZE		0x4
# define COMMAND_SIZE		0x1
# define ARGV_SIZE			0x1

# include "libft.h"

/*
** NEED CONNECT WITH GLOBAL ADDRESS
*/
# include "op.h"
# include <fcntl.h>
# include <stdint.h>
# include "list.h"

t_option g_option[OP_ARR_SIZE];

typedef struct		s_file
{
	int				fd;
	off_t			ptr_to_start_code;
	char			*ptr_buff;
	char			*file_name;
	size_t			buff_index;
	size_t			nline_code_start;
	size_t			curr_nline;
	size_t			curr_nsymb;
	size_t			cmmnd_len;
	size_t			cmmnt_len;
	size_t			curr_block_size;
	uint8_t			cmmnt_status;
	uint8_t			name_status;
	t_header		box;
	t_marker_lst	*lst_label;
	t_marker_lst	*lst_head;
}					t_file;

typedef struct		s_argv_param
{
	int				curr_argv;
	int				cmmnd_argc;
	int				cmmnd_argv_size;
	int				cmmnd_id;
	int				curr_cmmnd_size;
}					t_argv_param;

typedef struct		s_argv
{
	int				value;
	int				typel;
}					t_argv;

int					def_t_fileype_destination(char *argv, t_file *obj);
int					srch_frst_cmmnd(t_file *obj);
int					def_comment(char *str);
int					def_player_name(char *str, t_file *obj);
int					def_main_comment(char *str, t_file *obj);
int					def_marker(char *str, t_file *obj);
int					def_cmmnd(char *line, t_file *obj);
int					def_cmnd_init_size(int asm_cmmnd_id, int *t_dir);
int					def_type_cmmnd_argv(char **str);
int					grap_cmmnd(char *line, t_file *obj);
int					def_type_argv(char **d, t_file *o, T_ARGV_P *p, t_argv *v);
int					argv_val(char **s, t_file *o, t_argv_param *op, t_argv *v);
int					asm_code_generate(t_file *obj);
int					buffering_data(t_file *obj, ARV *op, t_argv *ar);
int					buffering_argv(int value, int size, t_file *obj);
void				int_to_byte(unsigned int value, int size, char **str);
int					cmp_argv_type(int fnd_type, int *cmmd_hexa, int *num_argv);
int					signed_hexa(int value, int label_size, char **data);
int					asm_collect_data(t_file *obj);
void				asm_usage(void);
void				symb_position_calc(size_t *nline, size_t *symb, char *c);
int					add_argv_size(int argv, int *t_dir, int block_size);
void				marker_add_to_lst(char *name, t_marker_lst **lst);
int					def_trush_after_argv(char *str, t_argv_param *op);
void				fopen_error(char *file_name);
int					err_to_long_name(size_t lenght);
int					err_text_comment(size_t lenght);
void				asm_lexical_err(size_t nline, size_t symb);
int					asm_err_b_line(size_t nline, size_t symb);
int					asm_err_end_line(size_t nline, size_t symb);
void				asm_double_name_err(size_t nline, size_t symb);
void				asm_double_comment_err(size_t nline, size_t symb);
int					err_undef_data(size_t nline, char *trush);
int					cmmnd_argv_err(size_t nline, int argv);
int					cmmnd_name_err(size_t nline, char *data, size_t *len);
int					warning_err_mark(size_t nline, char *data, size_t *c_len);
int					ususpected_error(void);
int					empty_file(void);
int					new_line_error(void);
int					undef_instruction_error(void);

#endif
