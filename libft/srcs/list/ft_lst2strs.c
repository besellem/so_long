/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:37:01 by besellem          #+#    #+#             */
/*   Updated: 2021/06/29 18:02:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdlib.h"
#include "ft_string.h"

/*
** Convert a list to a `char **'
*/
char	**ft_lst2strs(t_list **lst)
{
	size_t	tmp_len;
	char	**new;
	t_list	*tmp;
	size_t	i;

	if (!lst || !*lst)
		return (NULL);
	new = ft_calloc(ft_lstsize(*lst) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp_len = ft_strlen(tmp->content);
		new[i] = (char *)ft_calloc(tmp_len + 1, sizeof(char));
		if (!new[i])
			return (ft_strsfree(i, new));
		ft_memcpy(new[i++], tmp->content, tmp_len);
		tmp = tmp->next;
	}
	new[i] = NULL;
	return (new);
}
