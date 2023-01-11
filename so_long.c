/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/11 03:01:23 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 13)
		move_player(game, game->player->pos_x - 1, game->player->pos_y);
	else if (keycode == 0)
		move_player(game, game->player->pos_x, game->player->pos_y - 1);
	else if (keycode == 1)
		move_player(game, game->player->pos_x + 1, game->player->pos_y);
	else if (keycode == 2)
		move_player(game, game->player->pos_x, game->player->pos_y + 1);
	else if (keycode == 53)
		exit_game(game);
	return (0);
}

void	check_map_name(char *filepath)
{
	char	*res;

	res = ft_strnstr(filepath, ".ber", ft_strlen(filepath));
	
	if (!res)
		print_error("Map extension file must end with .ber\n", 1);
	if (ft_strncmp(res, ".ber", ft_strlen(res)))
		print_error("Map extension file must end with .ber\n", 1);
}

int main(int argc, char *argv[])
{
  	if (argc != 2)
		print_error("Not enough arguments! the Map is required\n", 1);
	check_map_name(argv[1]);
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Map File Not Found!\n", 1);
	t_game *game = malloc(sizeof(t_game));
	t_player *player = malloc(sizeof(t_player));
	if (!game || !player)
		print_error("Memory was not allocated1\n", 1);
	init_game(game, player, fd);
	check_map(game);
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->nbr_rows * 46, game->nbr_cols * 45, "So Long!");
	render_map(game);
	mlx_hook(game->mlx_window, 2, 0, key_hook, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}