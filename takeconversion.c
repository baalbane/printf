#include "ft_printf.h"

int launchprintarg(va_list arg, const char *str, int *tabarg, int *index)
{

	if(str[*index] == 's' || str[*index] == 'S')
	{
		if(str[*index] == 'S')
			tabarg[7] = 2;
		prints(arg, tabarg);
	}
	else if (str[*index] == 'p')
	{

	}
	else if (str[*index] == 'd' || str[*index] == 'D')
	{
		if(str[*index] == 'D')
			tabarg[7] = 2;
		printd(arg, tabarg);
	}
	else if (str[*index] == 'i')
	{

	}
	else if (str[*index] == 'o' || str[*index] == 'O')
	{

	}
	else if (str[*index] == 'u' || str[*index] == 'U')
	{

	}
	else if (str[*index] == 'x' || str[*index] == 'X')
	{

	}
	else if (str[*index] == 'c' || str[*index] == 'C')
	{

	}
	else
	{
		*index--;
		//printwithoutarg(tabarg);
	}
	*index++;
	return(1);

}
