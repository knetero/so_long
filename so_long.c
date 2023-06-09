/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:51:26 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/03 11:41:54 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_error(void)
{
	write(1, "Error: map is too big !\n", 25);
	exit(1);
}

int	par_ac2(int i, t_vars v)
{
	while (v.s != NULL)
	{
		free(v.s);
		i++;
		v.s = get_next_line(v.fd);
	}
	free(v.s);
	return (i);
}

int	par_ac(int ac, char **av, int i)
{
	t_vars	v;

	v.fd = 0;
	if (ac == 2)
	{
		if (!(check_ber(av[1])))
			return (write(1, "Error: in map extention !\n", 27), 1);
		v.fd = open(av[1], O_RDWR);
		if (v.fd < 0)
		{
			write(1, "Error: in opening the file !\n", 30);
			exit(1);
		}
		v.s = get_next_line(v.fd);
		if (!v.s)
			return (write(1, "Error: The map is empty !\n", 27), 1);
		i = par_ac2(i, v);
		return (close(v.fd), i);
	}
	else
		return (write(1, "Error: in the arguments !\n", 27), 1);
}

int	main(int argc, char **argv)
{
	t_vars	v;

	v.j = 0;
	v.i = 0;
	v.i = par_ac(argc, argv, v.i);
	if (v.i == 1)
		exit(1);
	if (v.i > 29)
		p_error();
	v.map = malloc(sizeof(char *) * (v.i + 1));
	if (!v.map)
		return (free(v.map), 0);
	v.fd = open(argv[1], O_RDONLY);
	if (v.fd < 0)
		return (free(v.map), 0);
	while (v.j < v.i)
		v.map[v.j++] = get_next_line(v.fd);
	v.map[v.j] = NULL;
	close(v.fd);
	check_len_walls(v.map, v.i);
	check_components(v.map);
	copy_player(copy_map(v.map, v.i));
	graphics(v.map, v.i);
}
