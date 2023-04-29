/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_graphics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:56:53 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/29 14:49:45 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close(void)
{
    exit(0);
}
void    render_img(t_vars *v)
{
    v->i = 0;
    while(v->map[v->i])
    {
        v->j = 0;
        while (v->map[v->i][v->j] != '\n')
        {
            mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->floor, 60 * v->j, 60 * v->i);
            if(v->map[v->i][v->j] == '1')
                mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->wall, 60 * v->j, 60 * v->i);
            if(v->map[v->i][v->j] == 'P')
                mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->player, 60 * v->j, 60 * v->i);
            if(v->map[v->i][v->j] == 'C')
                mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->coins, 60 * v->j, 60 * v->i);
            if(v->map[v->i][v->j] == 'E')
                mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->exit, 60 * v->j, 60 * v->i);
            v->j++;
        }
        v->i++;
    }
}

void    count_c(t_vars *v)
{
    int i;
    int j;

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

void    graphics(char **map, int w)
{
    t_vars v;

    v.x = 0;
    v.y = 0;
    v.i = 0;
    v.j = 0;
    v.w = 60;
    v.h = 60;
    v.moves = 0;
    v.map = map;
    count_c(&v);
    v.h = ft_strlen(map[v.i]) - 1;
    v.mlx_ptr =  mlx_init();
    v.win_ptr = mlx_new_window(v.mlx_ptr, v.h * 60, w *60, "so_long");
    v.wall = mlx_xpm_file_to_image(v.mlx_ptr, "textures/wall.xpm", &v.w, &v.h);
    v.floor = mlx_xpm_file_to_image(v.mlx_ptr, "textures/floor.xpm", &v.w, &v.h);
    v.player = mlx_xpm_file_to_image(v.mlx_ptr, "textures/player.xpm", &v.w, &v.h);
    v.left_player = mlx_xpm_file_to_image(v.mlx_ptr, "textures/left_player.xpm", &v.w, &v.h);
    v.coins = mlx_xpm_file_to_image(v.mlx_ptr, "textures/coins.xpm", &v.w, &v.h);
    v.exit = mlx_xpm_file_to_image(v.mlx_ptr, "textures/exit.xpm", &v.w, &v.h);
    if(!v.exit || !v.wall || !v.floor || !v.player || !v.coins)
        ft_puterror("Error: textures not found !\n");
    render_img(&v);
    mlx_hook(v.win_ptr, 2, 1L<<0, keys, &v);
    mlx_hook(v.win_ptr, 17, 1L<<0, ft_close, NULL);
    mlx_loop(v.mlx_ptr);
}
