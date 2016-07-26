/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:08:17 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/26 19:12:52 by baalbane         ###   ########.fr       */
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
