/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:55:02 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/14 20:14:15 by abazerou         ###   ########.fr       */
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

typedef struct var
{
    char **map;
    char *s;
    int fd;
    int i;
    int j;
    int x;
    int c;
    int p;
    int e;
    int len;
}vars;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include "get_next_line.h"

void    ft_puterror(char *s);
void	ft_putstr_fd(char *s, int fd);
int     check_ber(char *s);
void    check_c2(vars v);
void    check_c(char **map, int len_v);
void    check_wall2(char **map, int len_v);
void    check_wall(char **map, int len_v);

#endif