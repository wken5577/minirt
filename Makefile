# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:09:57 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/27 20:54:34 by hyunkyu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	minirt

SRCS	=	main.c \
			mlx_utils.c \
			mini_rt.c	\
			vector/ray.c \
			vector/vector_operator.c \
			vector/vector_utility.c \
			vector/vector.c \
			parsing/parsing.c \
			parsing/parsing_utils.c \
			parsing/parsing_utils1.c \
			color/color_utils.c \
			color/color_utils1.c \

SRCS_DIR = srcs
OBJS_DIR = objs

DEPS = $(OBJS:.o=.d)

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

# ${OBJS_DIR}:
# 	@echo "Build ${NAME}"
# 	@mkdir -p ${OBJS_DIR}
# 	@mkdir -p ${OBJS_DIR}/vector
# 	@mkdir -p ${OBJS_DIR}/parsing
# 	@mkdir -p ${OBJS_DIR}/color

CC		=	cc 
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g

all		: $(NAME)

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@echo "Build ${NAME}"
	@mkdir -p ${OBJS_DIR}
	@mkdir -p ${OBJS_DIR}/vector
	@mkdir -p ${OBJS_DIR}/parsing
	@mkdir -p ${OBJS_DIR}/color
	${CC} ${CFLAGS}  -c $< -o $@ -MD

$(NAME): $(OBJS)
	@make -C ./srcs/get_next_line
	@make -C ./srcs/libft
	@make -C ./srcs/mlx
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./srcs/get_next_line/libgnl.a ./srcs/libft/libft.a libmlx.dylib
	@echo "Build ${NAME}: done"

clean	:
	@make -C ./srcs/get_next_line clean
	@make -C ./srcs/libft clean
	@make -C ./srcs/mlx clean
	@rm -rf ${OBJS_DIR}

fclean	: clean
	@make -C ./srcs/get_next_line fclean
	@make -C ./srcs/libft fclean
	@make -C ./srcs/mlx clean
	@rm -rf	$(NAME)

re		:
	@make fclean
	@make all

-include $(DEPS)

.PHONY	: all clean fclean re
