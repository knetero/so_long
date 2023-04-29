/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:30:01 by abazerou          #+#    #+#             */
/*   Updated: 2023/04/19 02:00:52 by abazerou         ###   ########.fr       */
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
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
}