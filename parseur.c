/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:08:06 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/26 19:16:36 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int filltabargflag2(va_list arg, const char *str, int *tabarg, int *index)
{
	if (str[*index] == 'h')
	{
		*index++;
		if (str[*index] == 'h')
			tabarg[7] = 0 * (*index++);
		else
			tabarg[7] = 1;
	}
	else if (str[*index] == 'l')
	{
		*index++;
		if (str[*index] == 'l')
			tabarg[7] = 2 + 0 * (*index++);
		else
			tabarg[7] = 1;
	}
	else if (str[*index] == 'j')
		tabarg[7] = 4;
	else if (str[*index] == 'z')
		tabarg[7] = 5;
	else
		return (launchprintarg);
	return (filltabargflag(arg, str, tabarg, index));
}

int filltabargprec(va_list arg, const char *str, int *tabarg, int *index)
{
	if (str[*index] == '.' && str[*index + 1] == '*')
	{
		tabarg[6] = va_arg(arg, int);
		*index++;
	}
	else if (str[*index] == '.' && str[*index + 1] >= '0' && str[*index + 1] <= '0')
		tabarg[6] = takenbr(str, index);
	else
		return (filltabargflag2(arg, str, tabarg, index));
	return (filltabargflag(arg, str, tabarg, index));
}

int filltabargfield(va_list arg, const char *str, int *tabarg, int *index)
{
	if (str[*index] == '*')
	{
		tabarg[5] = va_arg(arg, int);
		*index++;
	}
	else if (str[*index] >= '0' && str[*index] <= '0')
		tabarg[5] = takenbr(str, index);
	else
		return (filltabargprec(arg, str, tabarg, index));
	return (filltabargflag(arg, str, tabarg, index));
}

int filltabargflag(va_list arg, const char *str, int *tabarg, int *index)
{
	if ((str[*index] == '#' ? (tabarg[0] = 1) : 0) || (str[*index] == '0' ? (tabarg[1] = 1) : 0)
	|| (str[*index] == '-' ? (tabarg[2] = 1) : 0) || (str[*index] == '+' ? (tabarg[3] = 1) : 0)
	|| (str[*index] == ' ' ? (tabarg[4] = 1) : 0))
	{
		*index++;
		return (filltabargflag(arg, str, tabarg, index));
	}
	return (filltabargfield(arg, str, tabarg, index));
}
