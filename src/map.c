/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:18:17 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/10 04:36:34 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
