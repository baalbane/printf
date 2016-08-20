/* ************************************************************************** */
/*                                                                            */
/*   printd.c                                                                 */
/*                                                                            */
/*   By: baalbane <marvin@42.fr>                                              */
/*                                                                            */
/*   Created: 2016/07/28                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printd(va_list arg, args *new)
{
ft_putnbr(va_arg(arg, int));
	return(1);
}
