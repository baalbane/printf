/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:14:51 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/20 18:31:15 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printx(va_list *arg, t_args *new, char a)
{
	int	minu;

	minu = a == 'X' ? 0 : 1;
	if (new->tabarg[7] == 0)
		new->str = ft_itoabase_unsigned((unsigned char)va_arg(*arg, int),
			16, minu);
	else if (new->tabarg[7] == 1)
		new->str = ft_itoabase_unsigned((unsigned short)va_arg(*arg,
			unsigned int), 16, minu);
	else if (new->tabarg[7] == 2)
		new->str = ft_itoabase_unsigned((long)va_arg(*arg, long), 16, minu);
	else if (new->tabarg[7] == 3)
		new->str = ft_itoabase_unsigned(va_arg(*arg, unsigned long long),
			16, minu);
	else if (new->tabarg[7] == 4)
		new->str = ft_itoabase_unsigned((uintmax_t)va_arg(*arg, uintmax_t),
			16, minu);
	else if (new->tabarg[7] == 5)
		new->str = ft_itoabase_unsigned((ssize_t)va_arg(*arg,
			ssize_t), 16, minu);
	else
		new->str = ft_itoabase_unsigned((unsigned int)va_arg(*arg,
			int), 16, minu);
	return (1);
}
