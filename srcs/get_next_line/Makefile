# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyu <hyunkyu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/12/27 20:47:54 by hyunkyu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 			get_next_line_bonus.c \
				get_next_line_utils_bonus.c  \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libgnl.a

$(NAME)	: $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	
.c.o :
	@$(CC) $(FLAGS) -o $@ -c $< -I .

all	: $(NAME)

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f $(NAME)

re	:	
	@make fclean 
	@make all

.PHONY	:	all clean fclean re
