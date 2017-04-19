/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:24:24 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/29 14:17:51 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		field(t_args *new, char conv)
{
	char	a;

	a = ' ';
	if (new->tabarg[2] == -1 && new->tabarg[1] == 1
	&& (new->tabarg[6] <= -1 || !ft_strchr("diouxX", conv)))
		a = '0';
	while (ft_strlen(new->str) < new->tabarg[5])
	{
		if (new->tabarg[2] == -1)
			new->str = ft_stradd(new->str, a, 0);
		else
			new->str = ft_stradd(new->str, a, 1);
	}
	return (1);
}
