/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:42:10 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/08 15:04:58 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
# include <stdio.h>
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
t_list	*new(void);
void	add_front(t_list **begin, t_list *new);
void	clear_and_print(t_list **lst);

#endif