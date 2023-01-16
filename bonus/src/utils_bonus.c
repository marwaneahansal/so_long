/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:44:05 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/16 02:33:01 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_game(t_game *game)
{
	free(game->player);
	free(game->map);
	free(game->map_2d);
	free(game->orig_map_2d);
	free(game);
	exit(0);
}

void	print_error(char *error, int exit_code)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error, 2);
	exit(exit_code);
}

void	show_nbr_movements(t_game *game)
{
	char	*nbr_move;
	char	*nbr_move_str;
	
	nbr_move = ft_itoa(game->player->movements_nbr);
	nbr_move_str = ft_strdup("Nbr of movements: ");
	nbr_move_str = ft_strjoin(nbr_move_str, nbr_move);
	mlx_string_put(game->mlx, game->mlx_window, 10, 10, 0x00000000, nbr_move_str);
	free(nbr_move_str);
	free(nbr_move);
}
