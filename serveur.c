/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:58:55 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/17 16:52:40 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_usr2(int pid)
{
	if (kill(pid, SIGUSR2) == -1)
	{
		write(1, "Error: Signal not send\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	send_usr1(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
	{
		write(1, "Error: Signal not send\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	trait(int sign, siginfo_t *info, void *ucontext)
{
	static t_list		*res = NULL;
	static unsigned int	tmp = 255;

	(void)ucontext;
	tmp = (tmp << 1) + (sign == SIGUSR2);
	if ((tmp & 0xFF00) >= 32768)
	{
		if (res == NULL)
			res = new(&res, info->si_pid);
		(res->i) = res->i + 1;
		res->buffer[res->i] = (char)(tmp & 0x00FF);
		if (res->i == 1023)
		{
			res->i++;
			add_front(&res, new(&res, info->si_pid));
		}
		if (res->buffer[res->i] == 0)
		{
			clear_and_print(&res);
			res = NULL;
			send_usr2(info->si_pid);
		}
		tmp = 255;
	}
	send_usr1(info->si_pid);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = &trait;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
	return (0);
}
