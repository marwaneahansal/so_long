/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:01:06 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/04 03:38:45 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    player_flood_fill(char **map, int x, int y)
{
    // printf("x = %d || y = %d\n", x, y);
    if (x < 0 || y < 0 || x > 4 || y > 12)
        return ;
    if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'B')
        return ;
    map[x][y] = 'B';
    player_flood_fill(map, x - 1, y);
    player_flood_fill(map, x + 1, y);
    player_flood_fill(map, x, y + 1);
    player_flood_fill(map, x, y - 1);
    return ;
}