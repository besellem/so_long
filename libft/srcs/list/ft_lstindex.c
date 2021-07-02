/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:35:08 by besellem          #+#    #+#             */
/*   Updated: 2021/06/29 17:36:44 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** Return the nth node of a list
*/
t_list	*ft_lstindex(t_list *lst, size_t index)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (i == index)
			return (tmp);
		++i;
		tmp = tmp->next;
	}
	return (NULL);
}
