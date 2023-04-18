/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:55:02 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/18 01:50:32 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_vars
{
    char **map;
    char *s;
    void *player;
    void *coins;
    void *exit;
    void *floor;
    void *wall;
    void *mlx_ptr;
    void *win_ptr;
    void *image;
    int fd;
    int i;
    int j;
    int x;
    int y;
    int c;
    int p;
    int e;
    int len;
    int w;
    int h;
}t_vars;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include "get_next_line.h"

int     check_ber(char *s);
void    ft_puterror(char *s);
void	ft_putstr_fd(char *s, int fd);
void    check_c2(t_vars v);
void    check_c(char **map, int len_v);
void    check_wall2(char **map, int len_v);
void    check_wall(char **map, int len_v);
void    graphics(char **map, int len);
void    render_img(t_vars *v, char **map, int w);


#endif