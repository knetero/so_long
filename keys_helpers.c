/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:48:48 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/28 19:15:45 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    right_key_helper(t_vars *v, int i, int j)
{
    if(v->map[i][j + 1] == 'C')
        v->c--;
    if(v->map[i][j + 1] == 'E')
    {
        if(v->c == 0)
        {
            ft_putstr_fd("Good job!\n", 1);
            exit(0);
        }
        else
            return;
    }
    v->map[i][j + 1] = 'P';
    v->moves++;
    v->map[i][j] = '0';
}

void    left_key_helper(t_vars *v, int i, int j)
{
    if(v->map[i][j - 1] == 'C')
        v->c--;
    if(v->map[i][j - 1] == 'E')
    {
        if(v->c == 0)
        {
            ft_putstr_fd("Good job!\n", 1);
            exit(0);
        }
        else
            return;
    }
    v->map[i][j - 1] = 'P';
    v->moves++;
    v->map[i][j] = '0';
}

void    up_key_helper(t_vars *v, int i, int j)
{
    if(v->map[i - 1][j] == 'C')
        v->c--;
    if(v->map[i - 1][j] == 'E')
    {
        if(v->c == 0)
        {
            ft_putstr_fd("Good job!\n", 1);   
            exit(0);
        }
        else
            return;
    }
    v->map[i - 1][j] = 'P';
    v->moves++;
    v->map[i][j] = '0';
}
void    down_key_helper(t_vars *v, int i, int j)
{
    if(v->map[i + 1][j] == 'C')
        v->c--;
    if(v->map[i + 1][j] == 'E')
    {
        if(v->c == 0)
        {
            ft_putstr_fd("Good job!\n", 1); 
            exit(0);
        }  
        else
            return;
    }
    v->map[i + 1][j] = 'P';
    v->moves++;
    v->map[i][j] = '0';
}
int   keys(int key, t_vars *v)
{
    if (key == 53)
        exit(0);
    if (key == 2)
        right_key(v);
    else if(key == 0)
        left_key(v);
    else if(key == 13)
        up_key(v); 
    else if(key == 1)
        down_key(v);
    ft_putnbr_fd(v->moves, 1);
    ft_putstr_fd(" Moves\n", 1);
    mlx_clear_window(v->mlx_ptr, v->win_ptr);
    render_img(v);
    return(0);
}