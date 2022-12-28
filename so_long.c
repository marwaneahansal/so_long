/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:51 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/28 02:41:14 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

int main(void)
{
  	void	*mlx;
	void	*mlx_win;

	ft_putstr_fd("Test Libft", 1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long!");
	mlx_loop(mlx);
  	(void)mlx_win;
}