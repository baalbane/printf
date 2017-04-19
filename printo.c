/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:27:34 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/20 18:30:54 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printo(va_list *arg, t_args *new)
{
	if (new->tabarg[7] == 0)
		new->str = ft_itoabase_unsigned((unsigned char)va_arg(*arg, int), 8, 0);
	else if (new->tabarg[7] == 1)
		new->str = ft_itoabase_unsigned((unsigned short)va_arg(*arg,
			unsigned int), 8, 0);
	else if (new->tabarg[7] == 2)
		new->str = ft_itoabase_unsigned((long)va_arg(*arg, long), 8, 0);
	else if (new->tabarg[7] == 3)
		new->str = ft_itoabase_unsigned(va_arg(*arg, unsigned long long), 8, 0);
	else if (new->tabarg[7] == 4)
		new->str = ft_itoabase_unsigned((uintmax_t)va_arg(*arg,
			uintmax_t), 8, 0);
	else if (new->tabarg[7] == 5)
		new->str = ft_itoabase_unsigned((ssize_t)va_arg(*arg, ssize_t), 8, 0);
	else
		new->str = ft_itoabase_unsigned((unsigned int)va_arg(*arg, int), 8, 0);
	return (1);
}
