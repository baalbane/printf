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

int		printc(va_list arg, int *tabarg)
{
	ft_putchar(va_arg(arg, int));
	return(1);
}
