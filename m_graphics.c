/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_graphics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:56:53 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/02 11:25:39 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_exit(t_vars *v)
{
	if (v->c)
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->r_f,
			60 * v->j, 60 * v->i);
	else
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->r_e,
			60 * v->j, 60 * v->i);
}

int	ft_close(void)
{
	exit(0);
}

void	render_img(t_vars *v)
{
	v->i = 0;
	while (v->map[v->i])
	{
		v->j = 0;
		while (v->map[v->i][v->j] != '\n')
		{
			mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->r_f,
				60 * v->j, 60 * v->i);
			if (v->map[v->i][v->j] == '1')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->r_w,
					60 * v->j, 60 * v->i);
			else if (v->map[v->i][v->j] == 'P')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->r_p,
					60 * v->j, 60 * v->i);
			else if (v->map[v->i][v->j] == 'C')
				mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->r_c,
					60 * v->j, 60 * v->i);
			else if (v->map[v->i][v->j] == 'E')
				display_exit(v);
			v->j++;
		}
		v->i++;
	}
}

void	count_c(t_vars *v)
{
	int	i;
	int	j;

	v->c = 0;
	i = 0;
	while (v->map[i])
	{
		j = 0;
		while (v->map[i][j])
		{
			if (v->map[i][j] == 'C')
				v->c++;
			j++;
		}
		i++;
	}
}

void	graphics(char **map, int y)
{
	t_vars	v;

	v.x = 0;
	v.y = 0;
	v.i = 0;
	v.j = 0;
	v.w = 60;
	v.h = 60;
	v.moves = 0;
	v.map = map;
	v.x = ft_strlen(map[v.i]) - 1;
	count_c(&v);
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, v.x * 60, y * 60, "so_long");
	v.r_w = mlx_xpm_file_to_image(v.mlx_ptr, "textures/wall.xpm", &v.w, &v.h);
	v.r_f = mlx_xpm_file_to_image(v.mlx_ptr, "textures/floor.xpm", &v.w, &v.h);
	v.r_p = mlx_xpm_file_to_image(v.mlx_ptr, "textures/player.xpm", &v.w, &v.h);
	v.r_c = mlx_xpm_file_to_image(v.mlx_ptr, "textures/coins.xpm", &v.w, &v.h);
	v.r_e = mlx_xpm_file_to_image(v.mlx_ptr, "textures/exit.xpm", &v.w, &v.h);
	if (!v.r_e || !v.r_w || !v.r_f || !v.r_p || !v.r_c)
		ft_puterror("Error: textures not found !\n");
	render_img(&v);
	mlx_hook(v.win_ptr, 2, 0, keys, &v);
	mlx_hook(v.win_ptr, 17, 0, ft_close, NULL);
	mlx_loop(v.mlx_ptr);
}
