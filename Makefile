# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 17:26:08 by cfriot            #+#    #+#              #
#    Updated: 2015/04/05 15:15:48 by cfriot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	  ft_functions.c  \
	  ft_functions2.c  \
	  ft_functions3.c  \
	  ft_functions_list.c \
	  ft_ini_magic.c  \
	  ft_print.c      \
	  ft_do_magic.c   \
	  ft_tabcpy.c      \
	  ft_merge_tab.c   \
	  ft_print_list.c  \
	  ft_clear.c       \
	  ft_update_path.c \
	  ft_check.c       \
	  ft_tools_check.c \
	  ft_long_entry.c  \
	  ft_tools_state.c

OBJ = $(SRC:.c=.o)

.PHONY: all libft clean fclean re

all : libft $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a 
	@echo "!"
	@echo "$(NAME) compiled\033[0m"

libft :
	@make -C libft/

%.o : %.c
	@$(CC) -c $(CFLAGS) -I./includes/ -I./libft/includes $<
	@printf "\033[32m."

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mpush_swap objects deleted\033[0m"

fclean : allclean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

allclean :
	@make -C libft/ fclean
	@/bin/rm -f $(OBJ)
	@echo "\033[31mpush_swap objects deleted\033[0m"

re : fclean all
