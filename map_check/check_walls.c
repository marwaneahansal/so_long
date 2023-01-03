/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:16:25 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/02 05:39:08 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_rows(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i] && map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        j++;   
    }
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
    return (1);
}

int check_cols(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i] && map[i][j])
    {
        if (map[i][j] != '1')
            return (0);
        i++;   
    }
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

int check_walls(char **map)
{
    if (!check_rows(map) || !check_cols(map))
        return (0);
    return (1);
}