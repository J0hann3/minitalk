/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:58:55 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/05 13:24:02 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void	trait(int sign)
{
	write(1, "Hello", 5);
}

int	main()
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, trait);
	// sigaction(SIGUSR1, )
	while (1)
	{
		pause();
	}
	return (1);
}
