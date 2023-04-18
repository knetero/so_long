/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:51:26 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/18 05:20:03 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    replace_chr(char **copy_map, int i, int j)
{
    if (copy_map[i + 1][j] == 'C' || copy_map[i + 1][j] == '0')
        copy_map[i + 1][j] = 'P';
    if (copy_map[i - 1][j] == 'C' || copy_map[i - 1][j] == '0')
        copy_map[i - 1][j] = 'P';

    if (copy_map[i][j +1] == 'C' || copy_map[i][j +1] == '0')
        copy_map[i][j + 1] = 'P';
    if (copy_map[i][j - 1] == 'C' || copy_map[i][j - 1] == '0')
        copy_map[i][j - 1] = 'P';
}

void    copy_player(char **copy_map)
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
                printf("%d | %d -> %c\n", v.i, v.j, copy_map[v.i][v.j]);
                replace_chr(copy_map , v.i, v.j);
            }
            v.j++;
        }
       v.i++;
    }
    v.i = 0;
    while (copy_map[v.i])
    {
        printf("%s", copy_map[v.i++]);
    }
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
    // v.i = 0;
    // while (copy_map[v.i])
    // {
    //     printf("%s", copy_map[v.i++]);
    // }
    return (copy_map);
}

int par_ac(int ac, char **av, int i)
{
    t_vars v;

    v.fd = 0;
    if(ac == 2)
    {
        if(!(check_ber(av[1])))
            return(write(1, "Error: in map extention !\n", 26), 1);
        v.fd = open(av[1], O_RDONLY);
        if(v.fd < 0)
            return (0);
        v.s = get_next_line(v.fd);
        if(!v.s)
            return (write(1, "Error: The map is empty !\n", 20), 1);
        while(v.s != NULL)
        {
            free(v.s);
            i++;
            v.s = get_next_line(v.fd);
        }
        free(v.s);
        return (close(v.fd), i);
    }
    else
        return(write(1, "Error: in the arguments !\n", 26), 1);
}

int main(int argc , char **argv)
{
    t_vars v;

    v.j = 0;
    v.i = 0;
    v.i = par_ac(argc, argv, v.i);
    if(v.i == 1)
        exit(1);
    v.map = malloc(sizeof(char*) * (v.i + 1));
    if (!v.map)
        return (0);
    v.fd = open(argv[1], O_RDONLY);
    if(v.fd < 0)
        return (0);
    while(v.j <= v.i)
    {
        v.map[v.j++] = get_next_line(v.fd);  
    }
    close(v.fd);
    check_wall(v.map, v.i);
    check_c(v.map, v.i);
    // copy_player(copy_map(v.map, v.i));
    // v.j = 0;
    // while (v.map[v.j])
    // {
    //     printf("%s", v.map[v.j++]);
    // }
    graphics(v.map, v.i);
}