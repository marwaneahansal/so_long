/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:28 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/29 05:38:56 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef  struct s_game {
    size_t  nbr_cols;
    size_t  nbr_rows;
    char    *map;
    char    **map_2d;
} t_game;

#endif