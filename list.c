/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:42:51 by jvigny            #+#    #+#             */
/*   Updated: 2022/12/08 16:38:50 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*new(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->i = -1;
	new->next = NULL;
	return (new);
}

void	add_front(t_list **begin, t_list *new)
{
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

	begin = *lst;
	if (lst == NULL || *lst == NULL)
	{
		// write(1, "FUCK", 4);
		return ;
	}
	// write(1, "COUCOU", 6);
	lst_last = NULL;
	while (begin->next != NULL)
	{
		lst_last = begin;
		begin = begin->next;
		// write(1, "OKAY", 4);
	}
	write(1, begin->buffer, begin->i);
	// write(1, "FINI", 4);
	if (lst_last != NULL)
	{
		// write(1, "HEY", 3);
		lst_last->next = NULL;
	}
	else
	{
		// write(1, "HELLO", 5);
		*lst = NULL;
	}
	free(begin);
}

void	clear_and_print(t_list **lst)
{
	while (*lst != NULL)
		delete_print(lst);
}
