#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 20:11:35 by lmatvien          #+#    #+#              #
#    Updated: 2018/09/29 16:05:42 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
HEADER =  \n \n \
 ▄████▄   ▒█████   ██▀███  ▓█████  █     █░ ▄▄▄       ██▀███ \n\
 ▒██▀ ▀█  ▒██▒  ██▒▓██ ▒ ██▒▓█   ▀ ▓█░ █ ░█░▒████▄    ▓██ ▒ ██▒ \n\
 ▒▓█    ▄ ▒██░  ██▒▓██ ░▄█ ▒▒███   ▒█░ █ ░█ ▒██  ▀█▄  ▓██ ░▄█ ▒ \n \
 ▒▓▓▄ ▄██▒▒██   ██░▒██▀▀█▄  ▒▓█  ▄ ░█░ █ ░█ ░██▄▄▄▄██ ▒██▀▀█▄   \n \
 ▒ ▓███▀ ░░ ████▓▒░░██▓ ▒██▒░▒████▒░░██▒██▓  ▓█   ▓██▒░██▓ ▒██▒  \n \
 ░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒▓ ░▒▓░░░ ▒░ ░░ ▓░▒ ▒   ▒▒   ▓▒█░░ ▒▓ ░▒▓░  \n \
   ░  ▒     ░ ▒ ▒░   ░▒ ░ ▒░ ░ ░  ░  ▒ ░ ░    ▒   ▒▒ ░  ░▒ ░ ▒░  \n \
   ░        ░ ░ ░ ▒    ░░   ░    ░     ░   ░    ░   ▒     ░░   ░ \n \
   ░ ░          ░ ░     ░        ░  ░    ░          ░  ░   ░ \n \
||A ||||S ||||M ||||/ ||||D ||||I ||||S || \n \
||__||||__||||__||||__||||__||||__||||__|| \n \
|/__\||/__\||/__\||/__\||/__\||/__\||/__\| \n\n \
   __  __    ___    ___    _   _   _      ___    \n \
  |  \/  |  / _ \  |   \  | | | | | |    | __|   \n \
  | |\/| | | (_) | | |) | | |_| | | |__  | _|    \n \
  |_|  |_|  \___/  |___/   \___/  |____| |___|   \n \
 

#COLORSs
VIOLET      = \033[01;38;05;201m
RESET		= \033[m
RED         = \033[1;31m
CYAN        = \033[1;36m

NAME			= asm
LIB_MINI_NAME 	= lib_mini.a
ASM_LIB			= asmlib.a
DISASM_LIB		= disasmlib.a
ERROR_LIB		= error_description.a
LST_LIB			= lst_control.a
ODIR 			= obj
SDIR 			= srcs
LDIR 			= ./srcs/libft_mini
ERROR_DIR		= ./srcs/error_description
LST_DIR			= ./srcs/lst_control
DISASM_DIR		= ./srcs/disassembler

FLAGS  			= -Wall -Wextra -Werror

ASM_FILES = asm_main.c \
			asm_open_file.c \
			asm_def_properties_name.c \
			asm_def_properties_comment.c \
			asm_def_properties_cmmnd.c \
			asm_def_cmmnd_argv.c \
			asm_freader.c \
			asm_writer.c \
			asm_def_marker.c \
			asm_generator_code.c \
			asm_generator_tools.c \
			asm_generator_tools_scnd.c \
			asm_generator_tools_thr.c \
			asm_freader.c \

DISASM_FILES = 	ft_asm.c \
				ft_atoi_base.c \
				ft_memcpy_my.c \
				ft_printf.c \
				func_1.c \
				func_2.c \
				func_3.c \
				func_4.c \
				func_5.c \
				open_file.c \
				open_file_1.c \
				disassembler.c \

LST__FILES = lst_control.c \

ERROR_FILES =	open_file_err.c \
				player_name_err.c \
				player_comment_err.c \
				maintain_err.c \
				cmmnd_err.c \
				undefined_data_err.c \
				tools_err.c \

LIBFILE =   ft_atoi_base.c \
			ft_uitoa_base.c \
			ft_itoa.c \
			ft_ulltoa.c \
			ft_itoa_base.c \
			ft_strnew.c \
			ft_pow.c \
			ft_strchr.c \
			ft_dgt_quntt_i.c \
			ft_isdigit.c  \
			ft_strrchr.c \
			ft_putnbr_fd.c \
			ft_putstr_error.c \
			ft_str_del_newline.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strequ.c \
			ft_strlen.c \
			ft_strnlen.c \
	 		ft_strdup.c \
			ft_strjoin.c \
			ft_strstr.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_strncat.c \
			ft_strcat.c \
			get_next_line.c \
			ft_strsplit.c \
			ft_atoi.c \
			ft_swap.c \
			ft_to_uppercase.c \
			ft_to_lowercase.c \
			ft_deletewhitespace.c \
			ft_grap_to_whitespaces.c \
			ft_grap_to_whitespaces_or_char.c \
			ft_atoi_and_qntt_dgt.c \

LIB_OBJ =	$(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(LIBFILE)))
ASM_OBJ = $(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(ASM_FILES)))
ERROR_OBJ = $(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(ERROR_FILES)))
LST_OBJ = $(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(LST__FILES)))
DISASM_OBJ = $(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(DISASM_FILES)))

INC_PARSER = -I ./includes -I $(LDIR)
LST_HEADER = -I ./srcs/lst_control
DIS_HEADER = -I ./srcs/disassembler

all: $(NAME)

$(ODIR)/%.o: $(LDIR)/%.c | $(ODIR)
	@gcc -c $< -o $@ $(FLAGS)
	@echo "$(VIOLET)█$(RESET)\c)"

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	@gcc -c $(INC_PARSER) $(LST_HEADER) $(DIS_HEADER) $< -o $@ $(FLAGS)
	@echo "$(VIOLET)█$(RESET)\c)"

$(ODIR)/%.o: $(ERROR_DIR)/%.c | $(ODIR)
	@gcc -c -I $(LDIR) $< -o $@ $(FLAGS)
	@echo "$(RED)█$(RESET)\c)"

$(ODIR)/%.o: $(LST_DIR)/%.c | $(ODIR)
	@gcc -c $< -o $@ $(FLAGS)
	@echo "$(RED)█$(RESET)\c)"

$(ODIR)/%.o: $(DISASM_DIR)/%.c | $(ODIR)
	@gcc -c -I $(LDIR) $< -o $@ $(FLAGS)
	@echo "$(VIOLET)█$(RESET)\c)"
$(ODIR):
	@echo "\033[35;1m>>>Creating objects folder...\033[0m"
		@echo "$(CYAN)Linking files ... $(RESET)\c)"
	@mkdir $(ODIR)

$(NAME): $(LIB_OBJ) $(ASM_OBJ) $(ERROR_OBJ) $(LST_OBJ) $(DISASM_OBJ)
	@ar rcs ./$(ODIR)/$(LIB_MINI_NAME) $(LIB_OBJ)
	@ar rcs ./$(ODIR)/$(ASM_LIB) $(ASM_OBJ)
	@ar rcs ./$(ODIR)/$(ERROR_LIB) $(ERROR_OBJ)
	@ar rcs ./$(ODIR)/$(LST_LIB) $(LST_OBJ)
	@ar rcs ./$(ODIR)/$(DISASM_LIB) $(DISASM_OBJ)
	@gcc ./$(ODIR)/$(LIB_MINI_NAME) ./$(ODIR)/$(ASM_LIB) ./$(ODIR)/$(ERROR_LIB) ./$(ODIR)/$(LST_LIB) ./$(ODIR)/$(DISASM_LIB) -o $(NAME) $(FLAGS)
	@echo "$(CYAN)█$(RESET)\c)"
	@echo "$(RED)$(HEADER)"
clean:
	@/bin/rm -rf $(LIB_OBJ) $(ASM_OBJ) $(ERROR_OBJ) $(LST_OBJ) $(DISASM_OBJ)
	@echo "\033[35;1m>>>Removed OBJ Files\033[0m"
	
fclean: clean
	@/bin/rm -rf $(ODIR) $(NAME)
	@echo "\033[35;1m>>>Removed executed files\033[0m"

re: fclean all