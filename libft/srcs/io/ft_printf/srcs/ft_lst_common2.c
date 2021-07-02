/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_common2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:21:20 by besellem          #+#    #+#             */
/*   Updated: 2020/11/27 14:53:23 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_internal.h"

void	add_lstd(t_data **s, char *str)
{
	size_t size;

	if (!str || ((size = ft_strlen(str)) == 0))
		return ;
	ft_lstd_add(s, ft_lstd_new(str, size));
}

void	ft_lstd_get_size(t_data **s, int *size)
{
	t_data	**tracer;

	tracer = s;
	while (*tracer)
	{
		*size += (*tracer)->size;
		tracer = &(*tracer)->next;
	}
}

void	ft_fill_ret(t_data **s, char **ret)
{
	t_data	**tracer;

	tracer = s;
	while (*tracer)
	{
		ft_strncat(*ret, (*tracer)->data, (*tracer)->size);
		tracer = &(*tracer)->next;
	}
}
