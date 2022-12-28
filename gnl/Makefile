# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 05:45:45 by mahansal          #+#    #+#              #
#    Updated: 2022/12/28 06:16:01 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

NAME 	= libgnl.a

SRCS 	= get_next_line.c get_next_line_utils.c

OBJS 	= $(SRCS:.c=.o)

CFLAGS 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@-ar rc ../libs/$(NAME) $(OBJS)

clean:
	@-rm -f $(OBJS)

fclean: clean
	@-rm -f ../libs/$(NAME)

re: fclean all
