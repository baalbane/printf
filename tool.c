/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:08:17 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/04 13:15:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		takenbr(const char *str, int *index)
{
	int		nbr;

	nbr = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
		nbr = nbr * 10 + str[(*index)++] - '0';
	return (nbr);
}

int		ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
	return (1);
}

int		ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int		ft_strchr(char *a, char b)
{
	while (*a)
	{
		if (*a == b)
			return (1);
		a++;
	}
	return (0);
}

int		ft_strlen(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
