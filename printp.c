/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:25:12 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/29 14:35:56 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printp(va_list *arg, t_args *new)
{
	new->str = ft_itoabase_unsigned(va_arg(*arg,
		unsigned long long int), 16, 1);
	if (new->tabarg[6] == 0 && new->str[0] == '0' && new->str[1] == '\0')
		new->str[0] = '\0';
	new->str = ft_stradd(new->str, 'x', 0);
	new->str = ft_stradd(new->str, '0', 0);
	return (1);
}
