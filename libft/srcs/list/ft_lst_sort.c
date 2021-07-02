/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:17:56 by besellem          #+#    #+#             */
/*   Updated: 2021/06/29 18:20:07 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** Sort a list.
** Slow algorithm, use ft_lst_qsort which implements quicksort algorithm for
** lists).
*/
void	ft_lst_sort(t_list **lst, int (*cmp)())
{
	t_list	*tmp;
	void	*ptr;

	if (!lst || !*lst || !(*cmp))
		return ;
	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (cmp(tmp->content, tmp->next->content) > 0)
		{
			ptr = tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = ptr;
			tmp = *lst;
		}
		else
			tmp = tmp->next;
	}
}
