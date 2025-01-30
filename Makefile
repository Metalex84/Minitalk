# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejango <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 18:13:44 by alejango          #+#    #+#              #
#    Updated: 2025/01/30 21:23:48 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & flags
CC	= 	cc
FLAGS	=	-Wall -Wextra -Werror -g3
RM	=	rm -rf

# Server info
SERVER_NAME     =	server
SERVER_SRC      =	server.c
SERVER_OBJ      =   $(SERVER_SRC:.c=.o)

# Client info
CLIENT_NAME		=	client
CLIENT_SRC      =   client.c
CLIENT_OBJ      =   $(CLIENT_SRC:.c=.o)

# LIBFT info
LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

# FT_PRINTF info
FT_PRINTF_DIR	=	./ft_printf
FT_PRINTF	=	$(FT_PRINTF_DIR)/libftprintf.a

# Main rules
all: 		$(LIBFT) $(FT_PRINTF) $(SERVER_NAME) $(CLIENT_NAME)

# Compile libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compile ft_printf
$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(SERVER_NAME):	$(SERVER_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SERVER_SRC) $(LIBFT) $(FT_PRINTF) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(CLIENT_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(CLIENT_SRC) $(LIBFT) $(FT_PRINTF) -o $(CLIENT_NAME)
	@echo "** MINITALK READY! **"

clean:
	@make -s -C ./ft_printf clean
	@make -s -C ./libft clean
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@make -s -C ./ft_printf clean
	@make -s -C ./libft clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY:		all clean fclean re
