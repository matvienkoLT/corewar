#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 20:11:35 by lmatvien          #+#    #+#              #
#    Updated: 2019/01/13 20:16:52 by nnaumenk         ###   ########.fr        #
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


#COLORSs
VIOLET      = \033[01;38;05;201m
RESET		= \033[m
RED         = \033[1;31m
CYAN        = \033[1;36m

NAME			= corewar
LIB_MINI_NAME 	= lib_mini.a
CMMND_LIB		= lib_cmmnd.a
BUILD_LIB		= buildlib.a
FT_PRINTF		= ./srcs/ft_printf/libftprintf.a

ODIR 			= obj
SDIR 			= srcs
LDIR 			= ./srcs/libft_mini
CMNND_DIR		= ./srcs/commands
BUILD_DIR		= ./srcs/build

FLAGS  			= -Wall -Wextra -Werror

CMMND_FILES =   ft_add.c \
				ft_aff.c \
				ft_and.c \
				ft_fork.c \
				ft_ld.c \
				ft_ldi.c \
				ft_lfork.c \
				ft_live.c \
				ft_lld.c \
				ft_lldi.c \
				ft_or.c \
				ft_st.c \
				ft_sti.c \
				ft_sub.c \
				ft_xor.c \
				ft_zjmp.c \

BUILD_FILE = convert_val.c \
			cycle_memory.c \
			find_error.c \
			ft_atoi_base.c \
			launch_command.c \
			main.c \
			make_check.c \
			make_field.c \
			open_file.c \
			open_file2.c \
			parsing_code.c \
			pc_algo.c \
			pc_init.c \
			print_winner.c \
			reset_hightlighting.c \
			start_vm.c \
			take_4_bytes.c \
			visualisation_1.c \
			visualisation_2.c \
			visualisation_3.c \
			flag_management.c \
			del_pl.c \
			ft_printf.c \
			ft_memcpy_my.c \

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
			ft_memalloc.c \
			ft_strdel.c \
			ft_bzero.c \
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

LIB_OBJ =	$(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(LIBFILE)))
CMMND_OBJ =	$(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(CMMND_FILES)))
BUILD_OBJ =	$(addprefix $(ODIR)/, $(patsubst %.c,%.o,$(BUILD_FILE)))

INC_PARSER = -I ./includes -I ./srcs/ft_printf/includes/ -I $(LDIR)

all: $(NAME)

$(ODIR)/%.o: $(LDIR)/%.c | $(ODIR)
	@gcc -c $< -o $@ $(FLAGS)
	@echo "$(VIOLET)█$(RESET)\c)"

$(ODIR)/%.o: $(CMNND_DIR)/%.c | $(ODIR)
	@gcc -c $(INC_PARSER) $< -o $@ $(FLAGS)
	@echo "$(VIOLET)█$(RESET)\c)"

$(ODIR)/%.o: $(BUILD_DIR)/%.c | $(ODIR)
	@gcc -c $(INC_PARSER) $< -o $@ $(FLAGS)
	@echo "$(VIOLET)█$(RESET)\c)"

$(ODIR):
	@echo "\033[35;1m>>>Creating objects folder...\033[0m"
		@echo "$(CYAN)Linking files ... $(RESET)\c)"
	@mkdir $(ODIR)

$(NAME): $(LIB_OBJ) $(CMMND_OBJ) $(BUILD_OBJ)
	@ar rcs ./$(ODIR)/$(LIB_MINI_NAME) $(LIB_OBJ)
	@ar rcs ./$(ODIR)/$(CMMND_LIB) $(CMMND_OBJ)
	@ar rcs ./$(ODIR)/$(BUILD_LIB) $(BUILD_OBJ)
	@echo "$(RED)\nLinking ft_printf ...\n $(RESET)\c)"
	@make -C ./srcs/ft_printf/
	@gcc ./$(ODIR)/$(LIB_MINI_NAME) ./$(ODIR)/$(CMMND_LIB) ./$(ODIR)/$(BUILD_LIB) $(FT_PRINTF) -lncurses  -o $(NAME)
	@echo "$(CYAN)█$(RESET)\c)"
	@echo "$(CYAN)$(HEADER)"
clean:
	@/bin/rm -rf $(LIB_OBJ)
	@make clean -C ./srcs/ft_printf/
	@echo "\033[35;1m>>>Removed OBJ Files\033[0m"
	
fclean: clean
	@/bin/rm -rf $(ODIR) $(NAME)
	@make fclean -C ./srcs/ft_printf/
	@echo "\033[35;1m>>>Removed executed files\033[0m"

re: fclean all
