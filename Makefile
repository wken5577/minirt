# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:09:57 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/27 16:24:25 by hyunkyu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	main.c \
			mlx_utils.c \
			mini_rt.c	\
			./vector/ray.c \
			./vector/vector_operator.c \
			./vector/vector_utility.c \
			./vector/vector.c \
			./parsing/parsing.c \
			./parsing/parsing_utils.c \
			./parsing/parsing_utils1.c \
			./color/color_utils.c \
			./color/color_utils1.c \

OBJS = $(SRCS:%.c=%.o)

OBJ_DIR = ./obj
OBJECTS = $(addprefix $(OBJ_DIR)/%.o, $(OBJS))
DEPS = $(OBJECTS:.o=.d)

CC		=	cc 
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g

all		: $(NAME)

$(OBJ_DIR)/%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@ -MD

$(NAME): $(OBJ)
	make -C ./get_next_line
	make -C ./libft
	make -C ./mlx
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) ./get_next_line/libgnl.a ./libft/libft.a libmlx.dylib

clean	:
	make -C ./get_next_line clean
	make -C ./libft clean
	make -C ./mlx clean
	rm -f $(OBJECTS) $(DEPS)

fclean	: clean
	make -C ./get_next_line fclean
	make -C ./libft fclean
	make -C ./mlx clean
	rm -rf	$(NAME)

re		:
	make fclean
	make all

-include $(DEPS)

.PHONY	: all clean fclean re
