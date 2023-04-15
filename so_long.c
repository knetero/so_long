/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:51:26 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/14 20:15:13 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int par_ac(int ac, char **av, int i)
{
    vars v;

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
    vars v;

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
    v.j = 0;
    while (v.map[v.j])
    {
        printf("%s", v.map[v.j++]);
    }
}