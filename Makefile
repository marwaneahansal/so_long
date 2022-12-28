# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:14:27 by mahansal          #+#    #+#              #
#    Updated: 2022/12/28 02:51:01 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= so_long

LIBFT_NAME 	= libft.a

SRCS 		= so_long.c 

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT_NAME): 
	@echo "Compiling libft..."
	@-make -C libft
	@echo "libft compiled"

$(NAME): $(OBJS) $(LIBFT_NAME)
	@echo "Compiling so_long..."
	@-$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "so_long compiled"

clean:
	@echo "Cleaning..."
	@-rm -f $(OBJS)
	@-make clean -C libft
	@echo "Cleaned"

fclean: clean
	@echo "Full cleaning..."
	@-rm -f $(NAME)
	@-make fclean -C libft
	@echo "Full cleaned"

re: fclean all