/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:03:16 by baalbane          #+#    #+#             */
/*   Updated: 2016/08/20 21:39:10 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_args
{
	int		*tabarg;
	char	*str;
}				args;

int		ft_printf(const char *format, ...);

int		takenbr(const char *str, int *index);
int		ft_putstr(char *str);
int		ft_putnbr(int a);
int		ft_putchar(char a);

int		fillinitab(int *tab);
int		*inittab();
args	*initlist();

int		launchprintarg(va_list arg, const char *str, args *new, int *index);

int		prints(va_list arg, args *new);

int		printd(va_list arg, args *new);

int		printc(va_list arg, args *new);

int		filltabargflag2(va_list arg, const char *str, args *new, int *index);
int		filltabargprec(va_list arg, const char *str, args *new, int *index);
int		filltabargfield(va_list arg, const char *str, args *new, int *index);
int		filltabargflag(va_list arg, const char *str, args *new, int *index);

#endif
