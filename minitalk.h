/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:42:10 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/19 10:50:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_list{
	struct s_list	*next;
	size_t			i;
	char			buffer[1024];
}	t_list;

size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
void	ft_putnbr_fd(int n, int fd);
t_list	*new(t_list **res, pid_t pid);
void	add_front(t_list **begin, t_list *new);
void	clear_and_print(t_list **lst);
void	delete(t_list **lst);
void	clear(t_list **lst);
void	send_usr2(int pid);
void	send_usr1(int pid);

#endif