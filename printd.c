/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:21:50 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/20 18:34:04 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printd(va_list *arg, t_args *new)
{
	if (new->tabarg[7] == 0)
		new->str = ft_itoabase((signed char)va_arg(*arg, int), 10);
	else if (new->tabarg[7] == 1)
		new->str = ft_itoabase((short)va_arg(*arg, int), 10);
	else if (new->tabarg[7] == 2)
		new->str = ft_itoabase((long int)va_arg(*arg, long int), 10);
	else if (new->tabarg[7] == 3)
		new->str = ft_itoabase(va_arg(*arg, long long int), 10);
	else if (new->tabarg[7] == 4)
		new->str = ft_itoabase((long long int)va_arg(*arg, intmax_t), 10);
	else if (new->tabarg[7] == 5)
		new->str = ft_itoabase((ssize_t)va_arg(*arg, ssize_t), 10);
	else
		new->str = ft_itoabase((int)va_arg(*arg, int), 10);
	if (new->str[0] == '\0')
		new->str = ft_stradd(new->str, '0', 0);
	return (1);
}
