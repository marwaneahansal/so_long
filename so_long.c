/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/31 05:46:49 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int key_hook(int keycode, t_game *game)
{
	/** 
		* ? w ==> 13
		* ? a ==> 0
		* ? s ==> 1
		* ? d ==> 2
	*/
	// TODO: check for the keycode and re-render the map accordingly
	if (keycode == 13) // w
	{
		//! update the map
		if (game->map_2d[game->player->pos_x - 1][game->player->pos_y] == '0')
		{
			game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
			game->map_2d[game->player->pos_x - 1][game->player->pos_y] = 'P';
			render_map(game->mlx, game->mlx_window, game, game->player);			
		}		
	}
	else if (keycode == 0) // a
	{
		//! update the map
		if (game->map_2d[game->player->pos_x][game->player->pos_y - 1] == '0')
		{
			game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
			game->map_2d[game->player->pos_x][game->player->pos_y - 1] = 'P';
			render_map(game->mlx, game->mlx_window, game, game->player);			
		}		
	}
	else if (keycode == 1) // s
	{
		//! update the map
		if (game->map_2d[game->player->pos_x + 1][game->player->pos_y] == '0')
		{
			game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
			game->map_2d[game->player->pos_x + 1][game->player->pos_y] = 'P';
			render_map(game->mlx, game->mlx_window, game, game->player);			
		}		
	}
	else if (keycode == 2) // d
	{
		//! update the map
		if (game->map_2d[game->player->pos_x][game->player->pos_y + 1] == '0')
		{
			game->map_2d[game->player->pos_x][game->player->pos_y] = '0';
			game->map_2d[game->player->pos_x][game->player->pos_y + 1] = 'P';
			render_map(game->mlx, game->mlx_window, game, game->player);			
		}		
	}
	return (0);
}

void	render_map(void *mlx, void *mlx_window, t_game *game, t_player *player)
{
	void	*ground_img;
	void	*wall_img;
	void	*player_img;
	void	*collectable_img;
	void	*exit_img;
	int		img_height;
	int		img_width;
	
	// *? load images for the mlbx
	ground_img = mlx_xpm_file_to_image(mlx, "./assets/ground.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &img_width, &img_height);
	player_img = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &img_width, &img_height);
	collectable_img = mlx_xpm_file_to_image(mlx, "./assets/collectable.xpm", &img_width, &img_height);
	exit_img = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &img_width, &img_height);

	if (!ground_img || !wall_img || !player_img || !collectable_img || !exit_img)
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
				mlx_put_image_to_window(mlx, mlx_window, exit_img, j * img_width, i * img_height);
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	// *? arguments check
  	if (argc != 2)
	{
		ft_putstr_fd("Not enough arguments! the Map is required\n", 2);
		exit(1);
	}
	// *? file map check
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Map File Not Found!\n", 2);
		exit(1);
	}
	// *? initialize t_game and t_player then read map line by line
	t_game *game = malloc(sizeof(t_game));
	t_player *player = malloc(sizeof(t_player));
	if (!game || !player)
		exit(1);
	char *line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Map is empty!\n", 2);
		exit(1);
	}
	game->nbr_rows = ft_strlen(line) - 1;
	game->nbr_cols = 0;
	game->map = NULL;
	game->map_2d = NULL;
	game->orig_map_2d = NULL;
	while (line)
	{
		game->map = ft_strjoin(game->map, line);
		line = get_next_line(fd);
		game->nbr_cols++;
	}
	// *? split the map
	game->map_2d = ft_split(game->map, '\n');
	game->orig_map_2d = ft_split(game->map, '\n');
	game->player = player;
	// *? initialize mlbx
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->nbr_rows * 46, game->nbr_cols * 45, "So Long!");
	// *? render the map
	render_map(game->mlx, game->mlx_window, game, player);
	// *? listen for key presses
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_loop(game->mlx);
	
	// *? free the variables
	free(game->map);
	free(line);
	free(game);
	return (0);
}