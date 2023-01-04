# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:14:27 by mahansal          #+#    #+#              #
#    Updated: 2023/01/03 23:29:50 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

NAME 		= so_long

LIBFT_NAME 	= libft.a

GNL_NAME 	= libgnl.a

SRCS 		= so_long.c map_check/check_components.c \
				map_check/check_ecp.c map_check/check_rect.c \
				map_check/check_walls.c map_check/check_path.c \

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

.SILENT: $(OBJS)

$(LIBFT_NAME): 
	@echo "Compiling libft..."
	@-make -C libft
	@echo "libft compiled"

$(GNL_NAME): 
	@echo "Compiling gnl..."
	@-make -C gnl
	@echo "gnl compiled"

$(NAME): $(LIBFT_NAME) $(GNL_NAME) $(OBJS)
	@echo "Compiling so_long..."
	@-$(CC) $(CFLAGS) $(OBJS) -L libs -lft -lgnl -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "so_long compiled"

clean:
	@echo "Cleaning..."
	@-rm -f $(OBJS)
	@-make clean -C libft
	@-make clean -C gnl
	@echo "Cleaned"

fclean: clean
	@echo "Full cleaning..."
	@-rm -f $(NAME)
	@-make fclean -C libft
	@-make fclean -C gnl
	@echo "Full cleaned"

re: fclean all