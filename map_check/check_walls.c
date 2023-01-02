/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:16:25 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/02 05:32:34 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_walls(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    // *? check the first row
    while (map[i] && map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        j++;   
    }

    // *? check the last row
    j = 0;
    i = 0;
    while (map[i] && map[i][j])
        j++;
    j -= 1;
    while (map[i] && map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        i++;
    }

    // *? check the first column
    j = 0;
    while (map[i] && map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        i++;   
    }

    // *? check the last column
    j = 0;
    i = 0;
    while (map[i])
        i++;
    i -= 1;
    while (map[i] && map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        j++;
    }
    return (1);
}