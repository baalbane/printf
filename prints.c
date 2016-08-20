#include "ft_printf.h"

int prints(va_list arg, args *new)
{

	ft_putstr(va_arg(arg, char*));

	return(1);

}
