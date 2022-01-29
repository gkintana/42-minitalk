# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 16:37:52 by gkintana          #+#    #+#              #
#    Updated: 2022/01/29 17:25:49 by gkintana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT_DIR	=	..
LIBFT		=	libft.a

INC_DIR		=	include
SRC_DIR		=	sources
OBJ_DIR		=	objects

SRCS		=	character.c \
				format_spec.c \
				ft_printf.c \
				hexadecimal.c \
				parse.c \
				pointer.c \
				signed.c \
				string.c \
				unsigned.c \
				util_general.c \
				util_signed.c \
				util_struct.c
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%c=%o))

LIB_AR		=	ar rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

DEFAULT		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[3;33m"
YELLOW_BU	=	"\033[1;4;33m"
CYAN		=	"\033[3;36m"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				@printf $(CYAN)
				$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

$(NAME):		$(LIBFT) $(OBJS)
				@printf $(DEFAULT)
				@$(LIB_AR) $(NAME) $(OBJS)
				@echo $(GREEN)"ft_printf Ready 💪"$(DEFAULT)

$(LIBFT):
				cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

all:			$(NAME)

bonus:			all

clean:
				@$(RM) $(OBJ_DIR)
				@echo $(RED)"Deleted ft_printf object files & object folder 🗃️"$(DEFAULT)

fclean:			clean
				@$(RM) $(NAME)
				@echo $(RED)"Deleted libftprintf.a 😱"$(DEFAULT)

re:				fclean all

norm:
				@echo $(DEFAULT)$(YELLOW_BU)"ft_printf .c files"$(DEFAULT)$(CYAN)
				@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c
				@echo $(DEFAULT)$(YELLOW_BU)"ft_printf .h file"$(DEFAULT)$(CYAN)
				@norminette -R CheckDefine $(INC_DIR)/*.h

.PHONY:			all clean fclean norm re bonus
