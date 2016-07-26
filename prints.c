#include "ft_printf.h"

int prints(va_list arg, int *tabarg)
{

	ft_putstr(va_arg(arg, char*));

	return(1);

}
