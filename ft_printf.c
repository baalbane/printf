/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:39:04 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/28 13:39:24 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		*tabarg;

	va_start(arg, format);
	i = -1;
	tabarg = inittab();
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			filltabargflag(arg, format, tabarg, &i);
		}
		else
			write(1, &format[i], 1);
	}
	return (0);
}

