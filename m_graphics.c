/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_graphics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:56:53 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/18 21:22:45 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    down_key(t_vars *v)
{
    int i;
    int j;
    
    i = 0;
     while(v->map[i])
    {
        j = 0;
        while(v->map[i][j])
        {
            if(v->map[i][j] == 'P'&& (v->map[i + 1][j] == 'C' || v->map[i + 1][j] == '0' || v->map[i + 1][j] == 'E'))
            {
                if(v->map[i + 1][j] == 'C')
                    v->c--;
                if(v->map[i + 1][j] == 'E')
                {
                    if(v->c == 0)   
                        exit(0);
                    else
                        return;
                }
                v->map[i + 1][j] = 'P';
                v->moves++;
                v->map[i][j] = '0';
                return ;
            }
            j++;   
        }
        i++;
    }
}

void    up_key(t_vars *v)
{
    int i;
    int j;
    
    i = 0;
     while(v->map[i])
    {
        j = 0;
        while(v->map[i][j])
        {
            if(v->map[i][j] == 'P'&& (v->map[i - 1][j] == 'C' || v->map[i - 1][j] == '0' || v->map[i - 1][j] == 'E'))
            {
                if(v->map[i - 1][j] == 'C')
                    v->c--;
                if(v->map[i - 1][j] == 'E')
                {
                    if(v->c == 0)   
                        exit(0);
                    else
                        return;
                }
                v->map[i - 1][j] = 'P';
                v->moves++;
                v->map[i][j] = '0';
                return ;
            }
            j++;   
        }
        i++;
    }
}

void    left_key(t_vars *v)
{
    int i;
    int j;
    
    i = 0;
     while(v->map[i])
    {
        j = 0;
        while(v->map[i][j])
        {
            if(v->map[i][j] == 'P' && (v->map[i][j - 1] == 'C' || v->map[i][j - 1] == '0' || v->map[i][j - 1] == 'E'))
            {
                if(v->map[i][j - 1] == 'C')
                    v->c--;
                if(v->map[i][j - 1] == 'E')
                {
                    if(v->c == 0)   
                        exit(0);
                    else
                        return;
                }
                v->map[i][j - 1] = 'P';
                v->moves++;
                v->map[i][j] = '0';
                return ;
            }
            j++;   
        }
        i++;
    }
}

void    right_key(t_vars *v)
{
    int i;
    int j;
    
    i = 0;
     while(v->map[i])
    {
        j = 0;
        while(v->map[i][j] && v->map[i][j + 1])
        {
            if(v->map[i][j] == 'P' && (v->map[i][j + 1] == 'C' || v->map[i][j + 1] == '0' || v->map[i][j + 1] == 'E'))
            {
                if(v->map[i][j + 1] == 'C')
                    v->c--;
                if(v->map[i][j + 1] == 'E')
                {
                    if(v->c == 0)   
                        exit(0);
                    else
                        return;
                }
                v->map[i][j + 1] = 'P';
                v->moves++;
                v->map[i][j] = '0';
                return ;
            }
            j++;   
        }
        i++;
    }
}

int   keys(int key, t_vars *v)
{

    if (key == 53)
        exit(0);
    if (key == 2)
    {
        printf("right key\n");
        right_key(v);
    }
    else if(key == 0)
    {
        printf("left key\n");
        left_key(v);
    }
    else if(key == 13)
    {
        printf("up key\n");
        up_key(v); 
    }
    else if(key == 1)
    {
        printf("down key\n");
        down_key(v);
    }
    printf("%s %d", "Total moves: ", v->moves);
    mlx_clear_window(v->mlx_ptr, v->win_ptr);
    render_img(v);
    return(0);
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
    v.h = ft_strlen(map[v.i]) - 1;
    v.mlx_ptr =  mlx_init();
    v.win_ptr = mlx_new_window(v.mlx_ptr, v.h * 60, w *60, "so_long");
    v.wall = mlx_xpm_file_to_image(v.mlx_ptr, "textures/wall.xpm", &v.w, &v.h);
    v.floor = mlx_xpm_file_to_image(v.mlx_ptr, "textures/floor.xpm", &v.w, &v.h);
    v.player = mlx_xpm_file_to_image(v.mlx_ptr, "textures/player.xpm", &v.w, &v.h);
    v.coins = mlx_xpm_file_to_image(v.mlx_ptr, "textures/coins.xpm", &v.w, &v.h);
    v.exit = mlx_xpm_file_to_image(v.mlx_ptr, "textures/exit.xpm", &v.w, &v.h);
    v.map = map;
    render_img(&v);
    mlx_hook(v.win_ptr, 2, 1L<<0, keys, &v);
    mlx_loop(v.mlx_ptr);
}
