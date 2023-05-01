/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:55:02 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/01 19:52:26 by abazerou         ###   ########.fr       */
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
# include <sys/stat.h>
# include "get_next_line.h"

typedef struct s_vars
{
	char	**map;
	char	*s;
	void	*r_p;
	void	*r_c;
	void	*r_e;
	void	*r_f;
	void	*r_w;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		fd;
	int		i;
	int		j;
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
	int		len;
	int		w;
	int		h;
	int		moves;
}t_vars;

char	**copy_map(char **map, int len);
void	ft_puterror(char *s);
void	ft_putnbr_fd(int n, int fd);
void	check_c2(char **map, t_vars *v);
void	check_c3(t_vars *v);
void	check_components(char **map);
void	check_first_last_walls(char **map, int len_v);
void	check_len_walls(char **map, int len_v);
void	graphics(char **map, int len);
void	render_img(t_vars *v);
void	copy_player(char **copy_map);
void	replace_chr(char **copy_map, int i, int j);
void	is_mapvalid(char **copy_map);
void	right_key(t_vars *v);
void	left_key(t_vars *v);
void	up_key(t_vars *v);
void	down_key(t_vars *v);
void	right_key_helper(t_vars *v, int i, int j);
void	left_key_helper(t_vars *v, int i, int j);
void	up_key_helper(t_vars *v, int i, int j);
void	down_key_helper(t_vars *v, int i, int j);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		check_ber(char *s);
int		par_ac2(int i, t_vars v);
int		keys(int key, t_vars *v);
int		is_player_canpass(char **copy_map);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
