/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/20 04:19:02 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *filepath)
{
	char	*res;

	res = ft_strrchr(filepath, '.');
	if (!res)
		print_error("Map extension file must end with .ber\n", 1);
	if (ft_strlen(res) != 4 || ft_strncmp(res, ".ber", 4))
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
	t_player	player;
	t_game		game;

	if (argc != 2)
		print_error("Not enough arguments! the Map is required\n", 1);
	check_map_name(argv[1]);
	fd = check_fd(argv[1]);
	init_game(&game, &player, fd);
	check_map(&game);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, game.nbr_rows * 70,
			game.nbr_cols * 70, "So Long!");
	render_map(&game);
	mlx_hook(game.mlx_window, 2, 0, key_hook, &game);
	mlx_hook(game.mlx_window, 17, 0, (void *) exit_game, &game);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
