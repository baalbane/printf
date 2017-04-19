/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itaobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 15:23:00 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/20 19:21:41 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoabase(long long int n, int base)
{
	char			*new;
	long long int	tmp;
	int				size;
	int				neg;

	size = 0;
	neg = 0;
	if (n < 0 && ++size)
		neg = -2;
	tmp = n;
	while (tmp != 0 && ++size != 0)
		tmp = tmp / base;
	new = malloc(sizeof(char) * (size + 1));
	new[size] = '\0';
	while (n != 0)
	{
		new[--size] = n % base + '0' + (neg * (n % base));
		if (new[size] > '9')
			new[size] += 7;
		n = n / base;
	}
	if (size == 1)
		new[0] = '-';
	return (new);
}

char	*ft_itoabase_unsigned(unsigned long long int n, int base, int minu)
{
	char					*new;
	unsigned long long int	tmp;
	int						size;

	size = 1;
	tmp = n;
	while (tmp >= (unsigned long long)base && size++)
		tmp = tmp / base;
	new = malloc(sizeof(char) * (size + 1));
	new[size] = '\0';
	while (n >= (unsigned long long)base)
	{
		new[--size] = n % base + '0';
		new[size] > '9' ? new[size] += 7 + (minu * 32) : 0;
		n = n / base;
	}
	new[--size] = n + '0';
	new[size] > '9' ? new[size] += 7 + (minu * 32) : 0;
	return (new);
}

int		ft_atoibase(char *str, int base)
{
	int		i;

	i = 0;
	while (*str != '\0' && *str != ' ')
		i = i * base + *str++ - '0';
	return (i);
}
