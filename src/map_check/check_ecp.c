/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ecp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:46:07 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/10 05:54:44 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int count_charachters(char **map, char c)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int check_ecp(char **map)
{
    if (count_charachters(map, 'E') == 1
        && count_charachters(map, 'C') >= 1
        && count_charachters(map, 'P') == 1)
        return (1);
    return (0);
}