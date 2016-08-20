/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:36:29 by baalbane          #+#    #+#             */
/*   Updated: 2016/08/20 21:35:34 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_printf(const char *format, ...)
{
	args	*new;
	va_list	arg;
	int		i;
	int		*tabarg;

	va_start(arg, format);
	i = -1;
	new = initlist();
	//tabarg = inittab();
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			filltabargflag(arg, format, new, &i);
		}
		else
			write(1, &format[i], 1);
	}
	return (0);
}

