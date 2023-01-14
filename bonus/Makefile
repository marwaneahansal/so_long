# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 02:04:23 by mahansal          #+#    #+#              #
#    Updated: 2023/01/14 02:11:47 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= ../so_long_bonus

LIBFT_NAME 	= libft.a

SRCS 		= so_long_bonus.c src/map_check/check_map_bonus.c src/map_check/check_components_bonus.c \
				src/map_check/check_ecp_bonus.c src/map_check/check_rect_bonus.c \
				src/map_check/check_walls_bonus.c src/map_check/check_path_bonus.c \
				src/init_bonus.c src/utils_bonus.c src/map_bonus.c

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

.SILENT: $(OBJS)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@echo "Compiling so_long_bonus..."
	@-$(CC) $(CFLAGS) $(OBJS) -L ../libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "so_long_bonus compiled"

$(LIBFT_NAME): 
	@echo "Compiling libft..."
	@-make -C ../libft
	@echo "libft compiled"
	
clean:
	@echo "Cleaning..."
	@-rm -f $(OBJS)
	@-make clean -C ../libft
	@echo "Cleaned"

fclean: clean
	@echo "Full cleaning..."
	@-rm -f $(NAME)
	@-make fclean -C ../libft
	@echo "Full cleaned"

re: fclean all