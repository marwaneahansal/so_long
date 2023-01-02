/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:57:58 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/02 02:01:58 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_char(char c)
{
    char    *map_chars;
    
    map_chars = "01CEP";
    if (!ft_strchr(map_chars, c))
        return (0);
    return (1);
}

int check_components(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!check_char(map[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}