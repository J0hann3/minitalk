/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:40:21 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/12 12:22:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		nb;
	int		sign;
	size_t	i;
	size_t	j;

	i = 0;
	nb = 0;
	sign = 1;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		j++;
	}
	if (j == 0)
		return (-1);
	return (nb * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				tmp;

	nb = n;
	if (n < 0)
	{
		nb = 0 - n;
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		tmp = nb + '0';
		write(fd, &tmp, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
