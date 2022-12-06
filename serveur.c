/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:58:55 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/06 04:40:04 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	trait(int sign, siginfo_t *info, void *ucontext)
{
	static char			res[1024];
	static int			i = 0;
	static unsigned int	tmp = 255;

	(void)ucontext;
	tmp = tmp << 1;
	tmp = tmp + (sign == SIGUSR2);
	if ((tmp & 0xFF00) >= 32768)
	{
		res[i] = (char)(tmp & 0x00FF);
		if (res[i] == 0)
		{
			write(1, res, i);
			i = -1;
			kill(info->si_pid, SIGUSR2);
		}
		if (i == 1023)
		{
			write(1, res, i + 1);
			i = -1;
		}
		i++;
		tmp = 255;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = &trait;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("%d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
	return (1);
}
