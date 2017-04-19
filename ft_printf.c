/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:36:29 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/05 13:59:33 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	size_t	size;

	va_start(arg, format);
	i = -1;
	size = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && i++ > -4)
		{
			if (format[i] == '\0')
				return (size);
			launchall(format, &i, &size, &arg);
		}
		else
			write(1, &format[i], 1);
		size++;
		if (format[i] == '\0')
			return (size);
	}
	va_end(arg);
	return (size);
}

int	launchall(const char *format, int *i, size_t *size, va_list *arg)
{
	t_args	*new;

	new = initlist();
	filltabargflag(arg, format, new, i);
	ft_putstr(new->str);
	*size += ft_strlen(new->str) - 1;
	if (new->id == 1)
		(*size)++;
	freelst(new);
	return (1);
}
