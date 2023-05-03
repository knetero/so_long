/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parcing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:13:15 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/02 21:26:45 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c3(t_vars *v, char **map)
{
	if (v->e != 1)
		ft_puterror("Error: No exit or Muliple Exits on the map !\n", map);
	if (v->p != 1)
		ft_puterror("Error: No player or more than one on the map !\n", map);
	if (v->c < 1)
		ft_puterror("Error: No collectibles on the map !\n", map);
}

void	check_c2(char **map, t_vars *v)
{
	if (map[v->i][v->j] != '1' && map[v->i][v->j] != '0'
		&& map[v->i][v->j] != 'P'
		&& map[v->i][v->j] != 'E'
		&& map[v->i][v->j] != 'C' && map[v->i][v->j] != '\n')
		ft_puterror("Error: unkown char on the map !\n", map);
	if (map[v->i][v->j] == 'E')
		v->e++;
	if (map[v->i][v->j] == 'P')
		v->p++;
	if (map[v->i][v->j] == 'C')
		v->c++;
}

void	check_components(char **map)
{
	t_vars	v;

	v.i = 0;
	v.j = 0;
	v.e = 0;
	v.c = 0;
	v.p = 0;
	while (map[v.i][v.j])
	{
		v.j = 0;
		while (map[v.i][v.j] != '\n')
		{
			check_c2(map, &v);
			v.j++;
		}
		v.i++;
	}
	check_c3(&v, map);
}

void	check_first_last_walls(char **map, int len_v)
{
	t_vars	v;

	v.j = 0;
	while (map[0][v.j] != '\n')
	{
		if ((map[0][v.j] != '1'))
			ft_puterror("Error: the map is not enclosed in walls !\n", map);
		v.j++;
	}
	v.j = 0;
	while (map[len_v - 1][v.j])
	{
		if ((map[len_v - 1][v.j] != '1'))
			ft_puterror("Error: the map is not enclosed in walls !\n", map);
		v.j++;
	}
}

void	check_len_walls(char **map, int len_v)
{
	t_vars	v;
	size_t	last_l;

	v.j = 0;
	v.x = 0;
	last_l = ft_strlen(map[len_v - 1]);
	if (last_l + 1 > 49)
		ft_puterror("Error: Map too big !\n", map);
	v.len = ft_strlen(map[v.x]) - 1;
	while (map[v.j] && v.j < len_v - 1)
	{
		if (ft_strlen(map[v.j]) != last_l + 1)
			ft_puterror("Error: in map lengh !\n", map);
		v.j++;
		if (map[v.x][0] != '1' || map[v.x][v.len - 1] != '1')
			ft_puterror("Error: the map is not enclosed in walls !\n", map);
		v.x++;
	}
	check_first_last_walls(map, len_v);
}
