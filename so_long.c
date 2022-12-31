/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/31 02:35:06 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_window;
	
  	if (argc != 2)
	{
		ft_putstr_fd("Not enough arguments! the Map is required\n", 2);
		exit(1);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Map File Not Found!\n", 2);
		exit(1);
	}
	t_game *game = malloc(sizeof(t_game));
	if (!game)
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
	while (line)
	{
		game->map = ft_strjoin(game->map, line);
		line = get_next_line(fd);
		game->nbr_cols++;
	}
	game->map_2d = ft_split(game->map, '\n');
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, game->nbr_rows * 46, game->nbr_cols * 45, "So Long!");
	void	*ground_img;
	void	*wall_img;
	void	*player_img;
	void	*collectable_img;
	void	*exit_img;
	int		img_height;
	int		img_width;
	ground_img = mlx_xpm_file_to_image(mlx, "./assets/ground.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &img_width, &img_height);
	player_img = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &img_width, &img_height);
	collectable_img = mlx_xpm_file_to_image(mlx, "./assets/collectable.xpm", &img_width, &img_height);
	exit_img = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &img_width, &img_height);

	if (!ground_img || !wall_img)
		printf("img error!\n");
	int i = 0;
	int j = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (game->map_2d[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_window, ground_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, wall_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_window, player_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, collectable_img, j * img_width, i * img_height);
			else if (game->map_2d[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_window, exit_img, j * img_width, i * img_height);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	free(game->map);
	free(line);
	free(game);
	return (0);
}