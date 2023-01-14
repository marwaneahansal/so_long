/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:47:47 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/14 02:07:25 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	check_char_in_map(char **map, char c)
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
			if (map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_composed(char *map)
{
	if (!ft_strchr(map, '0'))
		return (0);
	if (!ft_strchr(map, '1'))
		return (0);
	if (!ft_strchr(map, 'C'))
		return (0);
	if (!ft_strchr(map, 'P'))
		return (0);
	if (!ft_strchr(map, 'E'))
		return (0);
	return (1);
}

void	check_map(t_game *game)
{
	if (!check_composed(game->map))
		print_error("The map must compose with 0, 1, C, E and P\n", 1);
	if (!check_components(game->orig_map_2d))
		print_error("only 0, 1, C, E and P are allowed\n", 1);
	if (!check_ecp(game->orig_map_2d))
		print_error("the map must 1 exit, 1 player and at least 1 collectable\n",
			1);
	if (!check_rect(game->orig_map_2d))
		print_error("The map must be rectangular\n", 1);
	if (!check_walls(game->orig_map_2d))
		print_error("The map must be surrounded by walls\n", 1);
	player_flood_fill(game->orig_map_2d, game->player->pos_x,
		game->player->pos_y);
	if (!check_char_in_map(game->orig_map_2d, 'C'))
		print_error("The player cannot reach one of the collectables\n", 1);
	exit_flood_fill(game->orig_map_2d, game->player->pos_x,
		game->player->pos_y);
	if (!check_char_in_map(game->orig_map_2d, 'E'))
		print_error("The player cannot exit\n", 1);
}
