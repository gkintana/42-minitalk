# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 10:08:22 by gkintana          #+#    #+#              #
#    Updated: 2022/01/29 17:26:54 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
PRINTF_DIR	=	$(LIBFT_DIR)/ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

INC_DIR		=	include
SRC_DIR		=	sources

SRC_CLIENT	=	$(SRC_DIR)/client.c
OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)
SRC_SERVER	=	$(SRC_DIR)/server.c
OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

DEFAULT		=	"\033[0m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;33m"
CYAN		=	"\033[3;36m"

.c.o:
				@printf $(CYAN)
				$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)
				@printf $(DEFAULT)

$(LIBFT):
				make -C $(LIBFT_DIR) all

$(CLIENT):		$(OBJ_CLIENT)
				@printf $(CYAN)
				$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@ $(LIBFT) $(PRINTF)
				@echo $(DEFAULT)$(GREEN)"Minitalk Client Ready 🤯"$(DEFAULT)

$(SERVER):		$(OBJ_SERVER)
				@printf $(CYAN)
				$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@ $(LIBFT) $(PRINTF)
				@echo $(DEFAULT)$(GREEN)"Minitalk Server Ready 🤓"$(DEFAULT)
				
all:			$(LIBFT) $(CLIENT) $(SERVER)

bonus:			all

clean:
				make -C $(LIBFT_DIR) fclean
				$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:			clean
				$(RM) $(CLIENT) $(SERVER)

re:				fclean all

norm:
				@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c
				@norminette -R CheckDefine $(INC_DIR)/*.h

.PHONY:			all bonus clean fclean re norm
