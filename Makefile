# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:09:57 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/26 18:47:22 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	main.c \
			mlx_utils.c \
			ray.c \
			vector_operator.c \
			vector_utility.c \
			vector.c \
			parsing.c \
			
OBJS = $(SRCS:%.c=%.o)

CC		=	cc 
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@ ./get_next_line/libgnl.a ./libft/libft.a

$(NAME): $(OBJ)
	make -C ./get_next_line
	make -C ./libft
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME) 
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	make -C ./get_next_line clean
	make -C ./libft clean
	rm -rf $(OBJS)

fclean	: clean
	make -C ./get_next_line fclean
	make -C ./libft fclean
	rm -rf	$(NAME)

re		:
	make fclean
	make all