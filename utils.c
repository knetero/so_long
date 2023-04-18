/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:30:01 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/18 01:15:37 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *s)
{
	int i;
	
	i = ft_strlen(s);
	if (s[i - 4] == '.' && s[i - 3] == 'b' && s[i - 2] == 'e' && s[i - 1] == 'r')
		return(1);
	return (0);
}

void    ft_puterror(char *s)
{
    ft_putstr_fd(s, 1);
    exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}