# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:14:27 by mahansal          #+#    #+#              #
#    Updated: 2023/01/17 21:24:51 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= so_long

NAME_BONUS  = so_long_bonus

LIBFT_NAME 	= libft.a

SRCS 		= so_long.c src/map_check/check_map.c src/map_check/check_components.c \
				src/map_check/check_ecp.c src/map_check/check_rect.c \
				src/map_check/check_walls.c src/map_check/check_path.c \
				src/init.c src/utils.c src/map.c

BSRCS 		= bonus/so_long_bonus.c bonus/src/map_check/check_map_bonus.c bonus/src/map_check/check_components_bonus.c \
				bonus/src/map_check/check_ecp_bonus.c bonus/src/map_check/check_rect_bonus.c \
				bonus/src/map_check/check_walls_bonus.c bonus/src/map_check/check_path_bonus.c \
				bonus/src/init_bonus.c bonus/src/utils_bonus.c bonus/src/map_bonus.c

OBJS 		= $(SRCS:.c=.o)

BOBJS 		= $(BSRCS:.c=.o)


CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

# .SILENT: $(OBJS)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@echo "Compiling so_long..."
	@-$(CC) $(CFLAGS) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "so_long compiled"

$(LIBFT_NAME): 
	@echo "Compiling libft..."
	@-make -C libft
	@echo "libft compiled"

bonus: $(LIBFT_NAME) $(BOBJS)
	@echo "Compiling so_long_bonus..."
	@-$(CC) $(CFLAGS) $(BOBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "so_long_bonus compiled"
	
clean:
	@echo "Cleaning..."
	@-rm -f $(OBJS)
	@-rm -f $(BOBJS)
	@-make clean -C libft
	@echo "Cleaned"

fclean: clean
	@echo "Full cleaning..."
	@-rm -f $(NAME)
	@-rm -f $(NAME_BONUS)
	@-make fclean -C libft
	@echo "Full cleaned"

re: fclean all