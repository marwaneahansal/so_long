/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:28 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/01 01:01:46 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct  s_player {
    int pos_x;
    int pos_y;
} t_player;

typedef struct  s_game {
    void        *mlx;
    void        *mlx_window;
    size_t      nbr_cols;
    size_t      nbr_rows;
    char        *map;
    char        **map_2d;
    char        **orig_map_2d;
    t_player    *player;   
    
} t_game;


void	render_map(void *mlx, void *mlx_window, t_game *game, t_player *player);
int     key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int new_x_pos, int new_pos_y);

#endif