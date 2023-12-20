/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:59:04 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/20 18:18:40 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_boolean;

void	receive(int sign, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (sign == SIGUSR1)
		g_boolean = 1;
	if (sign == SIGUSR2)
		exit(EXIT_SUCCESS);
}

void	error(void)
{
	write(1, "Error: Signal not send\n", 23);
	exit(EXIT_FAILURE);
}

void	extract_binaire(char c, pid_t pid)
{
	unsigned char	binaire;
	int				j;

	j = 0;
	binaire = 0b10000000;
	while (j < 8)
	{
		g_boolean = 0;
		if ((c & binaire) == 0)
			if (kill(pid, SIGUSR1) == -1)
				error();
		if ((c & binaire) != 0)
			if (kill(pid, SIGUSR2) == -1)
				error();
		j++;
		binaire = binaire >> 1;
		while (1)
		{
			if (g_boolean == 1)
				break ;
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;
	size_t				size;
	size_t				i;

	if (argc != 3)
		return (write(1, "Nombre d'arguments incorrect\n", 29), -1);
	act.sa_sigaction = &receive;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (write(1, "PID incorrect\n", 14), -1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	size = ft_strlen(argv[2]);
	while (i <= size)
	{
		extract_binaire(argv[2][i], pid);
		i++;
	}
	return (0);
}
