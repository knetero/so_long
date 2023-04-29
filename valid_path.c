/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:31:19 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/28 20:09:40 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    is_mapvalid(char **copy_map)
{
    t_vars v;

    v.i = 0;
    v.e = 0;
    while(copy_map[v.i])
    {
        v.j = 0;
        while (copy_map[v.i][v.j])
        {
            if (copy_map[v.i][v.j] == 'C')
                ft_puterror("Error: Map is not valid !\n");
            if (copy_map[v.i][v.j] == 'E')
            {
                if (copy_map[v.i + 1][v.j] == 'P' || copy_map[v.i - 1][v.j] == 'P'
                 || copy_map[v.i][v.j + 1] == 'P' || copy_map[v.i][v.j - 1] == 'P')
                    v.e++;
            }
            v.j++;
        }
        v.i++;
    }
    if(v.e == 0)
        ft_puterror("Error: exit surrounded with walls\n");
}

void    replace_chr(char **copy_map, int i, int j)
{
    if (copy_map[i + 1][j] == 'C' || copy_map[i + 1][j] == '0')
        copy_map[i + 1][j] = 'P';
    if (copy_map[i - 1][j] == 'C' || copy_map[i - 1][j] == '0')
        copy_map[i - 1][j] = 'P';
    if (copy_map[i][j + 1] == 'C' || copy_map[i][j + 1] == '0')
        copy_map[i][j + 1] = 'P';
    if (copy_map[i][j - 1] == 'C' || copy_map[i][j - 1] == '0')
        copy_map[i][j - 1] = 'P';
}

int is_player_canpass(char **copy_map)
{
    t_vars v;

    v.i = 0;
    while(copy_map[v.i])
    {
        v.j = 0;
        while (copy_map[v.i][v.j])
        {
            if (copy_map[v.i][v.j] == 'P')
            {
                if (copy_map[v.i + 1][v.j] == 'C' || copy_map[v.i + 1][v.j] == '0')
                    return (1);
                if (copy_map[v.i - 1][v.j] == 'C' || copy_map[v.i - 1][v.j] == '0')
                    return (1);
                if (copy_map[v.i][v.j + 1] == 'C' || copy_map[v.i][v.j + 1] == '0')
                    return (1);
                if (copy_map[v.i][v.j - 1] == 'C' || copy_map[v.i][v.j - 1] == '0')
                    return (1);
            }
            v.j++;
        }
        v.i++;
    }
    return (0);
}

void    copy_player(char **copy_map)
{
    t_vars v;

    while(is_player_canpass(copy_map))
    {
        v.i = 0;
        while(copy_map[v.i])
        {
            v.j = 0;
            while (copy_map[v.i][v.j])
            {
                if (copy_map[v.i][v.j] == 'P')
                    replace_chr(copy_map , v.i, v.j);
                v.j++;
            }
            v.i++;
        }
    }
    is_mapvalid(copy_map);
}
char   **copy_map(char **map, int len)
{
    t_vars v;
    char **copy_map;


    v.i = 0;
    copy_map = malloc((sizeof(char *)) * len + 1);
    while(map[v.i])
    {
        copy_map[v.i] = ft_strdup(map[v.i]);
        v.i++;
    }
    copy_map[v.i] = NULL;
    return (copy_map);
}
