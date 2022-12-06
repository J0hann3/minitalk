/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:59:04 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/06 02:58:03 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_boolean;

void	receive(int sign, siginfo_t *info, void *ucontext)
{
	// if (info->si_pid != getpid())
	// 	exit(EXIT_FAILURE);
	if (sign == SIGUSR1)
		g_boolean = 1;
	if (sign == SIGUSR2)
	{
		write(1, "BRAVO MESSAGE BIEN RECU !!!\n", 28);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;
	unsigned char		binaire;
	size_t				size;
	int					i;
	int					j;

	act.sa_sigaction = &receive;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	i = 0;
	binaire = 0b10000000;
	if (argc != 3)
	{
		printf("Nombre d'arguments incorrect\n");
		return (-1);
	}
	pid = atoi(argv[1]);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	size = ft_strlen(argv[2]);
	while (i <= size)
	{
		j = 0;
		while (j < 8)
		{
			g_boolean = 0;
			if ((argv[2][i] & binaire) == 0)
				kill(pid, SIGUSR1);
			if ((argv[2][i] & binaire) != 0)
				kill(pid, SIGUSR2);
			j++;
			binaire = binaire >> 1;
			while (1)
			{
				if (g_boolean == 1)
					break ;
			}
		}
		binaire = 0b10000000;
		i++;
	}
	return (0);
}
