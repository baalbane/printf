/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:26:17 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/04 13:40:02 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printc(va_list *arg, t_args *new)
{
	if (new->tabarg[7] == 2)
		printwcharc(arg, new);
	else
	{
		new->str = malloc(sizeof(char) * 2);
		new->str[0] = (int)va_arg(*arg, int);
		if (new->str[0] <= 31)
		{
			new->str[0] = '\0';
			new->tabarg[5]--;
		}
		new->str[1] = '\0';
	}
	return (1);
}

int		printwcharc(va_list *arg, t_args *new)
{
	new->str = malloc(sizeof(char));
	new->str[0] = '\0';
	new->str = addwchar(new->str,
				do_mask(ft_itoabase(va_arg(*arg, wint_t), 2)));
	return (1);
}
