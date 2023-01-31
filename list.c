/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:42:51 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/17 16:52:02 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*new(t_list **begin, pid_t pid)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		clear(begin);
		write(1, "Malloc failed\n", 14);
		send_usr2(pid);
		exit(EXIT_FAILURE);
	}
	new->i = -1;
	new->next = NULL;
	return (new);
}

void	add_front(t_list **begin, t_list *new)
{
	if (new == NULL || begin == NULL)
		return ;
	new->next = (*begin);
	(*begin) = new;
}

t_list	*last(t_list *begin)
{
	if (begin != NULL)
		return (0);
	while (begin->next != NULL)
	{
		begin = begin->next;
	}
	return (begin);
}

void	delete_print(t_list **lst)
{
	t_list	*begin;
	t_list	*lst_last;

	if (lst == NULL || *lst == NULL)
		return ;
	begin = *lst;
	lst_last = NULL;
	while (begin->next != NULL)
	{
		lst_last = begin;
		begin = begin->next;
	}
	write(1, begin->buffer, begin->i);
	free(begin);
	if (lst_last != NULL)
		lst_last->next = NULL;
	else
		*lst = NULL;
}

void	clear_and_print(t_list **lst)
{
	while (*lst != NULL)
		delete_print(lst);
}
