/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/28 06:31:38 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int main(int argc, char *argv[])
{
  	if (argc != 2)
	{
		ft_putstr_fd("Not enough arguments! the Map is required\n", 2);
		exit(1);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Map File Not Found!\n", 2);
		exit(1);
	}

	char *map;
	char *line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	printf("The Map:\n%s\n", map);
}