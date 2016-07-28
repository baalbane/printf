#include "ft_printf.h"

int fillinitab(int *tab)
{
	int i;

	i = -1;
	while (++i < 9)
		tab[i] = -1;
	return(1);
}


int *inittab()
{
	int *tab;


	tab = malloc(sizeof(int) * 8);
	fillinitab(tab);
	return(tab);
}

