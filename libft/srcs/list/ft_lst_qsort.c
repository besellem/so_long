/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_qsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:27:10 by besellem          #+#    #+#             */
/*   Updated: 2021/06/29 18:17:08 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** QuickSort for lists.
*/

struct	s_list_qsort
{
	t_list	*head;
	t_list	*end;
	t_list	*new_head;
	t_list	*new_end;
	int		(*cmp)();
};

static void	__deref_ptrs__(t_list **cur, t_list **tail, t_list **tmp,
						   t_list **prev)
{
	if (*prev)
		(*prev)->next = (*cur)->next;
	(*tmp) = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = (*cur);
	(*tail) = (*cur);
	(*cur) = (*tmp);
}

static t_list	*__partition__(struct s_list_qsort *data)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*tail;
	t_list	*tmp;

	prev = NULL;
	cur = data->head;
	tail = data->end;
	while (cur != data->end)
	{
		if (data->cmp(data->end->content, cur->content) > 0)
		{
			if (NULL == data->new_head)
				data->new_head = cur;
			prev = cur;
			cur = cur->next;
		}
		else
			__deref_ptrs__(&cur, &tail, &tmp, &prev);
	}
	if (NULL == data->new_head)
		data->new_head = data->end;
	data->new_end = tail;
	return (data->end);
}

static t_list	*__quick_sort_recurse__(struct s_list_qsort data)
{
	t_list	*pivot;
	t_list	*tmp;

	if (!data.head || data.head == data.end)
		return (data.head);
	data.new_head = NULL;
	data.new_end = NULL;
	pivot = __partition__(&data);
	if (data.new_head != pivot)
	{
		tmp = data.new_head;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		data.head = data.new_head;
		data.end = tmp;
		data.new_head = __quick_sort_recurse__(data);
		tmp = ft_lstlast(data.new_head);
		tmp->next = pivot;
	}
	data.head = pivot->next;
	data.end = data.new_end;
	pivot->next = __quick_sort_recurse__(data);
	return (data.new_head);
}

void	ft_lst_qsort(t_list **head, int (*cmp)())
{
	const struct s_list_qsort	data = {
		.head = *head,
		.end = ft_lstlast(*head),
		.new_head = NULL,
		.new_end = NULL,
		.cmp = (*cmp)
	};

	if (!head || !*head || !(*cmp))
		return ;
	(*head) = __quick_sort_recurse__((struct s_list_qsort)data);
}
