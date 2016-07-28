/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:08:17 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/28 14:00:48 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		takenbr(const char *str, int *index)
{
	int		nbr;

	nbr = 0;
	while(str[*index] >= '0' && str[*index] <= '9')
		nbr = nbr * 10 + str[*index++] - '0';
	return(nbr);
}

int		ft_putstr(char *str)
{
	while(*str)
		write(1, &*str++, 1);
	return(1);
}

int		ft_putchar(char a)
{
	write(1, &a, 1);
	return(1);
}

int		ft_putnbr(int a)
{
	char l;

	l = a%10+'0';
	if(a > 9)
		ft_putnbr(a/10);
	write(1, &l, 1);
	return(1);
}
