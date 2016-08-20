/* ************************************************************************** */
/*                                                                            */
/*   printc.c                                                                 */
/*                                                                            */
/*   By: baalbane <marvin@42.fr>                                              */
/*                                                                            */
/*   Created: 2016/07/28                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printc(va_list arg, args *new)
{
	int a = va_arg(arg, int);
	ft_putchar((char)a);
	return(1);
}
