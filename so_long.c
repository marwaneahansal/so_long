/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/09 09:12:56 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x_pos, int new_y_pos)
{
	// *? put the current movemnts in the shell
	ft_putstr_fd("the number of movements: ", 1);
	ft_putnbr_fd(++game->player->movements_nbr, 1);
	ft_putchar_fd('\n', 1);
	
	if (game->map_2d[new_x_pos][new_y_pos] == 'C')
	{
		game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
		game->map_2d[new_x_pos][new_y_pos] = 'P';
		game->player->eaten_colle_nbr++;
		if (game->colle_nbr == game->player->eaten_colle_nbr)
			game->is_finished = 1;
		render_map(game->mlx, game->mlx_window, game, game->player);
	}
	else if (game->map_2d[new_x_pos][new_y_pos] == '0')
	{
		game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
		game->map_2d[new_x_pos][new_y_pos] = 'P';
		render_map(game->mlx, game->mlx_window, game, game->player);
	}
	else if (game->is_finished && game->map_2d[new_x_pos][new_y_pos] == 'E')
		exit_game(game);
		// mlx_clear_window(game->mlx, game->mlx_window);
}

int key_hook(int keycode, t_game *game)
{
	if (keycode == 13) // w
		move_player(game, game->player->pos_x - 1, game->player->pos_y);
	else if (keycode == 0) // a
		move_player(game, game->player->pos_x, game->player->pos_y - 1);
	else if (keycode == 1) // s
		move_player(game, game->player->pos_x + 1, game->player->pos_y);
	else if (keycode == 2) // d
		move_player(game, game->player->pos_x, game->player->pos_y + 1);
	else if (keycode == 53) // esc
		exit_game(game);
	return (0);
}

void	render_map(void *mlx, void *mlx_window, t_game *game, t_player *player)
{
	void	*ground_img;
	void	*wall_img;
	void	*player_img;
	void	*collectable_img;
	void	*closed_exit_img;
	void	*open_exit_img;
	int		img_height;
	int		img_width;
	
	// *? load images for the mlbx
	ground_img = mlx_xpm_file_to_image(mlx, "./assets/ground.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &img_width, &img_height);
	player_img = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &img_width, &img_height);
	collectable_img = mlx_xpm_file_to_image(mlx, "./assets/collectable.xpm", &img_width, &img_height);
	closed_exit_img = mlx_xpm_file_to_image(mlx, "./assets/closed_exit.xpm", &img_width, &img_height);
	open_exit_img = mlx_xpm_file_to_image(mlx, "./assets/open_exit.xpm", &img_width, &img_height);

	if (!ground_img || !wall_img || !player_img || !collectable_img || !closed_exit_img || !open_exit_img)
		printf("img error!\n");
	int i = 0;
	int j = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			// *? render the images according to the map
			if (game->map_2d[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_window, ground_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, wall_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == 'P')
			{
				// *? register the current possition of the player
				mlx_put_image_to_window(mlx, mlx_window, player_img, j * img_width, i * img_height);
				player->pos_x = i;
				player->pos_y = j;
			}
			else if (game->map_2d[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, collectable_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == 'E')
			{	
				if (!game->is_finished)
					mlx_put_image_to_window(mlx, mlx_window, closed_exit_img, j * img_width, i * img_height);
				else
					mlx_put_image_to_window(mlx, mlx_window, open_exit_img, j * img_width, i * img_height);
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	// *? arguments check
  	if (argc != 2)
		print_error("Not enough arguments! the Map is required\n", 1);
	
	// *? file map check
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Map File Not Found!\n", 1);
	
	// *? initialize t_game and t_player
	t_game *game = malloc(sizeof(t_game));
	t_player *player = malloc(sizeof(t_player));
	if (!game || !player)
		print_error("Memory was not allocated1\n", 1);
	
	init_game(game, player, fd);
	
	// ?* check the map if it's valid or not
	check_map(game);
	// *? initialize mlx
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->nbr_rows * 46, game->nbr_cols * 45, "So Long!");
	// *? render the map
	render_map(game->mlx, game->mlx_window, game, player);
	// *? listen for key presses
	mlx_hook(game->mlx_window, 2, 0, key_hook, game);
	// mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
	
	// *? free the variables
	exit_game(game);
	return (0);
}