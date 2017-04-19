/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:03:16 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/04 12:05:21 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <wchar.h>

typedef	struct	s_args
{
	int			*tabarg;
	char		*str;
	int			id;
}				t_args;

int				ft_printf(const char *format, ...);
int				launchall(const char *format, int *i, size_t *size,
					va_list *arg);

int				takenbr(const char *str, int *index);
int				ft_putstr(char *str);
int				ft_putchar(char a);
int				ft_strlen(char *a);
int				ft_strchr(char *a, char b);

int				fillinitab(int *tab);
int				*inittab(void);
t_args			*initlist(void);
int				freelst(t_args *todel);

int				launchprintarg(va_list *arg, const char *str, t_args *new,
					int *index);
int				emptystr(const char *str, t_args *new, int *index);
int				launchprintarg2(const char *str, t_args *new, int *index);

char			*ft_stradd(char *s1, char a, int id);
int				isnumberwithsign(char *s1);
char			*writenull(void);
char			*ft_strcpy(char	*a);
int				ft_strlennbr(char *a);

int				field(t_args *new, char conv);

int				precplus_dioux(t_args *new);
int				prec_s(t_args *new);
int				prec_p(t_args *new);
int				diesirae(t_args *new, char a);
int				diesirae_0(t_args *new, char a);

int				prints(va_list *arg, t_args *new);
char			*addwchar(char *str, char *new);
char			*do_mask(char *str);
int				printwchars(va_list *arg, t_args *new);

int				printd(va_list *arg, t_args *new);

int				printc(va_list *arg, t_args *new);
int				printwcharc(va_list *arg, t_args *new);

int				printp(va_list *arg, t_args *new);

int				printx(va_list *arg, t_args *new, char a);

int				printo(va_list *arg, t_args *new);

int				printu(va_list *arg, t_args *new);

char			*ft_itoabase(long long int n, int base);
char			*ft_itoabase_unsigned(unsigned long long int n, int base,
					int minus);
int				ft_atoibase(char *str, int base);

int				filltabargflag2(va_list *arg, const char *str, t_args *new,
					int *index);
int				filltabargprec(va_list *arg, const char *str, t_args *new,
					int *index);
int				filltabargfield(va_list *arg, const char *str, t_args *new,
					int *index);
int				filltabargflag(va_list *arg, const char *str, t_args *new,
					int *index);

#endif
