/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:08:06 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/04 13:47:28 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	filltabargflag2(va_list *arg, const char *str, t_args *new, int *index)
{
	if (str[*index] == 'h' && (*index)++ > -4 && new->tabarg[7] < 4)
	{
		if (str[*index] == 'h')
			new->tabarg[7] = 0 * (*index)++;
		else
			new->tabarg[7] = 1;
	}
	else if (str[*index] == 'l')
	{
		(*index)++;
		if (str[*index] == 'l')
			new->tabarg[7] = 3 + 0 * (*index)++;
		else
			new->tabarg[7] = 2;
	}
	else if (str[*index] == 'j')
		new->tabarg[7] = 4 + 0 * (*index)++;
	else if (str[*index] == 'z')
		new->tabarg[7] = 5 + 0 * (*index)++;
	else
		return (launchprintarg(arg, str, new, index));
	return (filltabargflag(arg, str, new, index));
}

int	filltabargprec(va_list *arg, const char *str, t_args *new, int *index)
{
	if (str[*index] == '.' && str[*index + 1] == '*')
	{
		new->tabarg[6] = va_arg(*arg, int);
		(*index) += 2;
	}
	else if (str[*index] == '.')
	{
		(*index)++;
		new->tabarg[6] = takenbr(str, index);
	}
	else if (str[*index] == '.')
		new->tabarg[6] = 0 * (*index)++;
	else
		return (filltabargflag2(arg, str, new, index));
	return (filltabargflag(arg, str, new, index));
}

int	filltabargfield(va_list *arg, const char *str, t_args *new, int *index)
{
	if (str[*index] == '*')
	{
		new->tabarg[5] = va_arg(*arg, int) + 0 * (*index)++;
		if (new->tabarg[5] < 0)
		{
			new->tabarg[5] = -new->tabarg[5];
			new->tabarg[2] = 1;
		}
	}
	else if (str[*index] >= '0' && str[*index] <= '9')
		new->tabarg[5] = takenbr(str, index);
	else
		return (filltabargprec(arg, str, new, index));
	return (filltabargflag(arg, str, new, index));
}

int	filltabargflag(va_list *arg, const char *str, t_args *new, int *index)
{
	if ((str[*index] == '#' ? (new->tabarg[0] = 1) : 0)
	|| (str[*index] == '0' ? (new->tabarg[1] = 1) : 0)
	|| (str[*index] == '-' ? (new->tabarg[2] = 1) : 0)
	|| (str[*index] == '+' ? (new->tabarg[3] = 1) : 0)
	|| (str[*index] == ' ' ? (new->tabarg[4] = 1) : 0))
	{
		(*index)++;
		return (filltabargflag(arg, str, new, index));
	}
	return (filltabargfield(arg, str, new, index));
}
