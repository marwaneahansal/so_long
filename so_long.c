/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/11 03:22:58 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *filepath)
{
	char	*res;

	res = ft_strnstr(filepath, ".ber", ft_strlen(filepath));
	if (!res)
		print_error("Map extension file must end with .ber\n", 1);
	if (ft_strncmp(res, ".ber", 4))
		print_error("Map extension file must end with .ber\n", 1);
}

int	check_fd(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY | O_DIRECTORY);
	if (fd > 0)
		print_error("Map is a directory!\n", 1);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		print_error("Map File Not Found!\n", 1);
	return (fd);
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_player	*player;
	t_game		*game;

	if (argc != 2)
		print_error("Not enough arguments! the Map is required\n", 1);
	check_map_name(argv[1]);
	fd = check_fd(argv[1]);
	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	if (!game || !player)
		print_error("Memory was not allocated1\n", 1);
	init_game(game, player, fd);
	check_map(game);
	game->mlx_window = mlx_new_window(game->mlx, game->nbr_rows * 46,
			game->nbr_cols * 45, "So Long!");
	render_map(game);
	mlx_hook(game->mlx_window, 2, 0, key_hook, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}