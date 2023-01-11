/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:57:21 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/11 03:31:28 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_rect(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = ft_strlen(map[0]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != x)
			return (0);
		y++;
	}
	while (map[y])
		y++;
	if (x < y + 1)
		return (0);
	return (1);
}
