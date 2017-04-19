/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabtool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:12:53 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/05 14:05:27 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fillinitab(int *tab)
{
	int i;

	i = -1;
	while (++i < 9)
		tab[i] = -1;
	return (1);
}

int		*inittab(void)
{
	int *tab;

	tab = malloc(sizeof(int) * 8);
	fillinitab(tab);
	return (tab);
}

t_args	*initlist(void)
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	new->tabarg = inittab();
	new->id = 0;
	return (new);
}

int		freelst(t_args *todel)
{
	free(todel->tabarg);
	free(todel->str);
	free(todel);
	return (1);
}
