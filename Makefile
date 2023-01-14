# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:14:27 by mahansal          #+#    #+#              #
#    Updated: 2023/01/14 01:59:50 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= so_long

LIBFT_NAME 	= libft.a

SRCS 		= so_long.c src/map_check/check_map.c src/map_check/check_components.c \
				src/map_check/check_ecp.c src/map_check/check_rect.c \
				src/map_check/check_walls.c src/map_check/check_path.c \
				src/init.c src/utils.c src/map.c

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

.SILENT: $(OBJS)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@echo "Compiling so_long..."
	@-$(CC) $(CFLAGS) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "so_long compiled"

$(LIBFT_NAME): 
	@echo "Compiling libft..."
	@-make -C libft
	@echo "libft compiled"
	
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