/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 07:42:12 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/09 09:14:22 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->pos_x = i;
				player->pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	read_map(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		print_error("Map is empty!\n", 1);
	game->nbr_rows = ft_strlen(line) - 1;
	while (line)
	{
		game->map = ft_strjoin(game->map, line);
		line = get_next_line(fd);
		free(line);
		game->nbr_cols++;
	}
}

int	count_collectables(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

void	init_game(t_game *game, t_player *player, int fd)
{
	player->movements_nbr = 0;
	player->eaten_colle_nbr = 0;
	game->nbr_rows = 0;
	game->nbr_cols = 0;
	game->colle_nbr = 0;
	game->is_finished = 0;
	game->player = player;
	read_map(game, fd);
	game->orig_map_2d = ft_split(game->map, '\n');
	game->map_2d = ft_split(game->map, '\n');
	get_player_pos(game->orig_map_2d, player);
	game->colle_nbr = count_collectables(game->map);
}
