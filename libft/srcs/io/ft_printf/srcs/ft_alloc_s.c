/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:06:02 by besellem          #+#    #+#             */
/*   Updated: 2020/11/27 14:52:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_internal.h"

void	ft_alloc_s(t_data **s, t_indicators t, va_list ap)
{
	char	*data;
	char	*sp;
	int		size;
	int		tmp;

	data = va_arg(ap, char *);
	data = data ? data : "(null)";
	size = ft_strlen(data);
	sp = NULL;
	if (t.dot >= 0)
		size = (size >= t.dot) ? t.dot : size;
	tmp = ft_strlen(data) + t.width - size;
	if ((t.dot >= 0 && t.zero >= 0) || t.width >= 0)
		sp = space_padding(data, tmp);
	(t.minus == -1) ? add_lstd(s, sp) : 0;
	ft_lstd_add(s, ft_lstd_new(data, size));
	(t.minus == 1) ? add_lstd(s, sp) : 0;
	ft_free(1, sp);
}
