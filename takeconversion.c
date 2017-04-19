/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeconversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:47:20 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/04 12:38:14 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		launchprintarg(va_list *arg, const char *str, t_args *new, int *index)
{
	if (ft_strchr("SDOUC", str[*index]))
		new->tabarg[7] = 2;
	if (ft_strchr("sS", str[*index]))
		prints(arg, new);
	else if (str[*index] == 'p')
		printp(arg, new);
	else if (ft_strchr("dDi", str[*index]))
		printd(arg, new);
	else if (ft_strchr("oO", str[*index]))
		printo(arg, new);
	else if (ft_strchr("uU", str[*index]))
		printu(arg, new);
	else if (ft_strchr("xX", str[*index]))
		printx(arg, new, str[*index]);
	else if (ft_strchr("cC", str[*index]))
	{
		printc(arg, new);
		if (new->str[0] == '\0')
			new->id = 1;
	}
	else
		emptystr(str, new, index);
	return (launchprintarg2(str, new, index));
}

int		emptystr(const char *str, t_args *new, int *index)
{
	new->str = malloc(sizeof(char) * 2);
	new->str[0] = str[*index];
	new->str[1] = '\0';
	return (1);
}

int		launchprintarg2(const char *str, t_args *new, int *index)
{
	if (str[*index] == 'p')
		prec_p(new);
	if (ft_strchr("dDioOuUxX", str[*index]))
		precplus_dioux(new);
	if (ft_strchr("sS", str[*index]) && new->tabarg[6] > -1)
		prec_s(new);
	if (new->tabarg[0] == 1 && ft_strchr("xX", str[*index])
			&& (new->tabarg[1] == -1 || new->tabarg[2] == 1))
		diesirae(new, str[*index]);
	if (new->tabarg[0] == 1 && new->str[0] != '0'
			&& ft_strchr("oO", str[*index]))
		new->str = ft_stradd(new->str, '0', 0);
	if (ft_strchr("dDi", str[*index]) && new->tabarg[3] == 1
			&& new->str[0] != '-')
		new->str = ft_stradd(new->str, '+', 0);
	else if (ft_strchr("dDi", str[*index]) && new->tabarg[4] == 1
			&& new->str[0] != '-')
		new->str = ft_stradd(new->str, ' ', 0);
	field(new, str[*index]);
	if (new->tabarg[0] == 1 && ft_strchr("xX", str[*index])
			&& new->tabarg[1] == 1 && new->tabarg[2] == -1)
		diesirae_0(new, str[*index]);
	return (1);
}
