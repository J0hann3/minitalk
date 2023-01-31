/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:56:56 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/19 10:48:32 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	delete(t_list **lst)
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
	free(begin);
	if (lst_last != NULL)
		lst_last->next = NULL;
	else
		*lst = NULL;
}

void	clear(t_list **lst)
{
	while (*lst != NULL)
		delete(lst);
}
