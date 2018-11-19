# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:21:48 by dalauren          #+#    #+#              #
#    Updated: 2018/07/18 17:04:25 by dalauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CC = gcc -Wall -Wextra -Werror

LIBFT = ./libft/

INC_DIR = includes/

SRC_DIR = src/

SRC = lem_in.c \
	  algo.c \
	  algo_2.c \
	  algo_3.c \
	  move.c \
	  move2.c \
	  move3.c \
	  move4.c \
	  move_ant.c \
	  cpy_tab.c \
	  free_all.c \
	  free_all2.c \
	  get_data.c \
	  parse_ant.c \
	  parse_room.c \
	  parse_room2.c \
	  get_data_connex.c \
	  check_data_connex.c \
	  check_data_connex2.c

DONE = [\033[0;32mDONE\033[0m]

OBJ = $(SRC:.c=.o)

RM = rm -f

SRC_F = $(addprefix $(SRC_DIR), $(SRC))

all : $(NAME) $(NAME2)

$(NAME): $(SRC_F)
		make -C $(LIBFT)
		$(CC) -c $(SRC_F) -I $(INC_DIR)
		$(CC) -o $(NAME) $(OBJ) -I $(INC_DIR) libft/libft.a
		@echo "Lem_in = $(DONE)"

clean:
		$(RM) $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
