/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:40:21 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/17 11:40:16 by jvigny           ###   ########.fr       */
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

int	ft_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\f'
		|| c == '\n' || c == '\v')
		return (1);
	return (0);
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
	while (ft_whitespace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		j++;
	}
	if (j == 0 || str[i] != '\0')
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
