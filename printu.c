/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:20:37 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/29 15:16:45 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printu(va_list *arg, t_args *new)
{
	if (new->tabarg[7] == 0)
		new->str = ft_itoabase_unsigned((unsigned char)va_arg(*arg,
			int), 10, 0);
	else if (new->tabarg[7] == 1)
		new->str = ft_itoabase_unsigned((unsigned short)va_arg(*arg,
			unsigned int), 10, 0);
	else if (new->tabarg[7] == 2)
		new->str = ft_itoabase_unsigned((unsigned long)va_arg(*arg,
		long), 10, 0);
	else if (new->tabarg[7] == 3)
		new->str = ft_itoabase_unsigned(va_arg(*arg,
			unsigned long long), 10, 0);
	else if (new->tabarg[7] == 4)
		new->str = ft_itoabase_unsigned((uintmax_t)va_arg(*arg,
			uintmax_t), 10, 0);
	else if (new->tabarg[7] == 5)
		new->str = ft_itoabase_unsigned((size_t)va_arg(*arg, size_t), 10, 0);
	else
		new->str = ft_itoabase_unsigned((unsigned int)va_arg(*arg, int), 10, 0);
	return (1);
}
