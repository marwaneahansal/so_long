/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:44:05 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/20 04:24:41 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	free(game->map);
	free(game->map_2d);
	free(game->orig_map_2d);
	exit(0);
}

void	print_error(char *error, int exit_code)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error, 2);
	exit(exit_code);
}
