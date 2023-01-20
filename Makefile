# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:14:27 by mahansal          #+#    #+#              #
#    Updated: 2023/01/20 04:28:24 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= so_long

NAME_BONUS  = so_long_bonus

LIBFT_NAME 	= libft.a

SRCS 		= so_long.c check_map.c check_components.c \
				check_ecp.c check_rect.c \
				check_walls.c check_path.c \
				init.c utils.c map.c

BSRCS 		= bonus/so_long_bonus.c bonus/src/map_check/check_map_bonus.c \
				bonus/src/map_check/check_components_bonus.c \
				bonus/src/map_check/check_ecp_bonus.c bonus/src/map_check/check_rect_bonus.c \
				bonus/src/map_check/check_walls_bonus.c bonus/src/map_check/check_path_bonus.c \
				bonus/src/init_bonus.c bonus/src/utils_bonus.c bonus/src/map_bonus.c

OBJS 		= $(SRCS:.c=.o)

BOBJS 		= $(BSRCS:.c=.o)


CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_NAME): 
	make -C libft

bonus: $(LIBFT_NAME) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	
clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C libft

re: fclean all