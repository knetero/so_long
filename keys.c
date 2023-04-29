/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:17:35 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/29 09:27:15 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    down_key(t_vars *v)
{
    v->i = 0;
    v->j = 0;
    while(v->map[v->i])
    {
        v->j = 0;
        while(v->map[v->i][v->j])
        {
            if(v->map[v->i][v->j] == 'P'&& (v->map[v->i + 1][v->j] == 'C' || v->map[v->i + 1][v->j] == '0' || v->map[v->i + 1][v->j] == 'E'))
            {
                down_key_helper(v, v->i, v->j);
                return ;
            }
            v->j++;   
        }
        v->i++;
    }
}

void    up_key(t_vars *v)
{
    v->i = 0;
    v->j = 0;
    while(v->map[v->i])
    {
        v->j = 0;
        while(v->map[v->i][v->j])
        {
            if(v->map[v->i][v->j] == 'P'&& (v->map[v->i - 1][v->j] == 'C' || v->map[v->i - 1][v->j] == '0' || v->map[v->i - 1][v->j] == 'E'))
            {
                up_key_helper(v, v->i, v->j);
                return ;
            }
            v->j++;   
        }
        v->i++;
    }
}

void    left_key(t_vars *v)
{
    v->i = 0;
    v->j = 0;
    while(v->map[v->i])
    {
        v->j = 0;
        while(v->map[v->i][v->j])
        {
            if(v->map[v->i][v->j] == 'P' && (v->map[v->i][v->j - 1] == 'C' || v->map[v->i][v->j - 1] == '0' || v->map[v->i][v->j - 1] == 'E'))
            {
                left_key_helper(v, v->i, v->j);
                return ;
            }
            v->j++;   
        }
        v->i++;
    }
}

void    right_key(t_vars *v)
{
    v->i = 0;
    v->j = 0;
    while(v->map[v->i])
    {
        v->j = 0;
        while(v->map[v->i][v->j] && v->map[v->i][v->j + 1])
        {
            if(v->map[v->i][v->j] == 'P' && (v->map[v->i][v->j + 1] == 'C' || v->map[v->i][v->j + 1] == '0' || v->map[v->i][v->j + 1] == 'E'))
            {
                right_key_helper(v, v->i, v->j);
                return ;
            }
            v->j++;   
        }
        v->i++;
    }
}