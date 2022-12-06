/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:59:04 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/06 05:02:58 by jvigny           ###   ########.fr       */
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
	{
		write(1, "BRAVO MESSAGE BIEN RECU !!!\n", 28);
		exit(EXIT_SUCCESS);
	}
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
			kill(pid, SIGUSR1);
		if ((c & binaire) != 0)
			kill(pid, SIGUSR2);
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
	size_t				i;

	if (argc != 3)
		return (printf("Nombre d'arguments incorrect\n"), -1);
	act.sa_sigaction = &receive;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	i = 0;
	pid = atoi(argv[1]);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (i <= ft_strlen(argv[2]))
	{
		extract_binaire(argv[2][i], pid);
		i++;
	}
	return (0);
}
