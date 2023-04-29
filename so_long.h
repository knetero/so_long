/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:55:02 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/28 19:17:00 by abazerou         ###   ########.fr       */
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
    int moves;
}t_vars;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include "get_next_line.h"

int     par_ac2(int i, t_vars v);
int     check_ber(char *s);
void    ft_puterror(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void    check_c2(t_vars *v);
void    check_c(char **map);
void    check_wall2(char **map, int len_v);
void    check_wall(char **map, int len_v);
void    graphics(char **map, int len);
void    render_img(t_vars *v);
char    **copy_map(char **map, int len);
void    copy_player(char **copy_map);
void    replace_chr(char **copy_map, int i, int j);
void    is_mapvalid(char **copy_map);
int     keys(int key, t_vars *v);
int     is_player_canpass(char **copy_map);
void    right_key(t_vars *v);
void    left_key(t_vars *v);
void    up_key(t_vars *v);
void    down_key(t_vars *v);
void    right_key_helper(t_vars *v, int i, int j);
void    left_key_helper(t_vars *v, int i, int j);
void    up_key_helper(t_vars *v, int i, int j);
void    down_key_helper(t_vars *v, int i, int j);

#endif