/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:59:04 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/05 14:25:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	pid;
	int	binaire;
	int	res;
	int	i;
	int	j;

	i = 0;
	binaire = 0b10000000;
	if (argc != 3)
	{
		printf("Erreur\n");
		return (-1);
	}
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		j = 0;
		while (j < 8)
		{
			res = argv[2][i] & binaire;
			if (res == 0)
				kill(pid, SIGUSR1);
			if (res != 0)
				kill(pid, SIGUSR2);
			printf("Binaire: %d \n", res);
			j++;
			binaire = binaire >> 1;
		}
		binaire = binaire >> 1;
		i++;
	}
	return (0);
}
