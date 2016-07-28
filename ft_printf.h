/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:03:16 by baalbane          #+#    #+#             */
/*   Updated: 2016/07/28 15:02:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		takenbr(const char *str, int *index);
int		ft_putstr(char *str);
int		ft_putnbr(int a);
int		ft_putchar(char a);

int		fillinitab(int *tab);
int		*inittab();

int		launchprintarg(va_list arg, const char *str, int *tabarg, int *index);

int		prints(va_list arg, int *tabarg);

int		printd(va_list arg, int *tabarg);

int		printc(va_list arg, int *tabarg);

int		filltabargflag2(va_list arg, const char *str, int *tabarg, int *index);
int		filltabargprec(va_list arg, const char *str, int *tabarg, int *index);
int		filltabargfield(va_list arg, const char *str, int *tabarg, int *index);
int		filltabargflag(va_list arg, const char *str, int *tabarg, int *index);

#endif
