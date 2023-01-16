/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:18:17 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/16 02:33:07 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	mlx_show_image(t_game *game, char *filename, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, filename, &img_width, &img_height);
	if (!img)
		print_error("Image Not found!\n", 1);
	mlx_put_image_to_window(game->mlx, game->mlx_window, img,
		x * img_width, y * img_height);
	mlx_destroy_image(game->mlx, img);
}

void	render_images(t_game *game, char map_char, int x, int y)
{
	if (map_char == '0')
		mlx_show_image(game, "./textures/ground.xpm", x, y);
	else if (map_char == '1')
		mlx_show_image(game, "./textures/wall.xpm", x, y);
	else if (map_char == 'C')
		mlx_show_image(game, "./textures/collectable.xpm", x, y);
	else if (map_char == 'P')
	{
		mlx_show_image(game, "./textures/player.xpm", x, y);
		game->player->pos_x = y;
		game->player->pos_y = x;
	}
	else if (map_char == 'E')
	{
		if (!game->is_finished)
			mlx_show_image(game, "./textures/closed_exit.xpm", x, y);
		else
			mlx_show_image(game, "./textures/open_exit.xpm", x, y);
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			render_images(game, game->map_2d[i][j], j, i);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_game *game)
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

void	move_player(t_game *game, int new_x_pos, int new_y_pos)
{
	if (game->map_2d[new_x_pos][new_y_pos] == 'C')
	{
		game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
		game->map_2d[new_x_pos][new_y_pos] = 'P';
		game->player->eaten_colle_nbr++;
		if (game->colle_nbr == game->player->eaten_colle_nbr)
			game->is_finished = 1;
		render_map(game);
	}
	else if (game->map_2d[new_x_pos][new_y_pos] == '0')
	{
		game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
		game->map_2d[new_x_pos][new_y_pos] = 'P';
		render_map(game);
	}
	else if (game->is_finished && game->map_2d[new_x_pos][new_y_pos] == 'E')
		exit_game(game);
	show_nbr_movements(game);
	game->player->movements_nbr++;
}
