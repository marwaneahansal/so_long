/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:01:06 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/10 05:54:44 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void    player_flood_fill(char **map, int x, int y)
{
    if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'B')
        return ;
    map[x][y] = 'B';
    player_flood_fill(map, x - 1, y);
    player_flood_fill(map, x + 1, y);
    player_flood_fill(map, x, y + 1);
    player_flood_fill(map, x, y - 1);
}

void    exit_flood_fill(char **map, int x, int y)
{
    if (map[x][y] == '1' || map[x][y] == 'H')
        return ;
    map[x][y] = 'H';
    exit_flood_fill(map, x - 1, y);
    exit_flood_fill(map, x + 1, y);
    exit_flood_fill(map, x, y + 1);
    exit_flood_fill(map, x, y - 1);
}