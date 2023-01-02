/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:57:58 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/02 01:05:00 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_components(char *map)
{
    if (ft_strchr(map, '0') && ft_strchr(map, '1')
        &&  ft_strchr(map, 'P') &&  ft_strchr(map, 'C')
        &&  ft_strchr(map, 'E'))
        return (1);
    return (0);
}