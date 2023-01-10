/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:28 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/10 03:48:55 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct  s_player {
    int pos_x;
    int pos_y;
    int movements_nbr;
    int eaten_colle_nbr;
} t_player;

typedef struct  s_game {
    void        *mlx;
    void        *mlx_window;
    size_t      nbr_cols;
    size_t      nbr_rows;
    char        *map;
    char        **map_2d;
    char        **orig_map_2d;
    int         colle_nbr;
    t_player    *player;
    int         is_finished;
    
} t_game;

void    check_map(t_game *game);
int     check_components(char **map);
int     check_ecp(char **map);
int     check_rect(char **map);
int     check_walls(char **map);
void    player_flood_fill(char **map, int x, int y);
void    exit_flood_fill(char **map, int x, int y);

void    init_game(t_game *game, t_player *player, int fd);
void	render_map(t_game *game);
int     key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int new_x_pos, int new_pos_y);

void    print_error(char *error, int exit_code);
void	exit_game(t_game *game);

#endif