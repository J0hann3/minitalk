/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:40:21 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/20 18:22:10 by jvigny           ###   ########.fr       */
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
