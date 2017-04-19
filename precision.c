/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:23:40 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/29 14:40:09 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precplus_dioux(t_args *new)
{
	while (ft_strlennbr(new->str) < new->tabarg[6])
		new->str = ft_stradd(new->str, '0', 0);
	if (new->str[0] == '0' && new->str[1] == '\0' && new->tabarg[6] == 0)
		new->str[0] = '\0';
	return (1);
}

int	prec_s(t_args *new)
{
	char	*tmp;
	int		i;

	if (ft_strlen(new->str) <= new->tabarg[6])
		return (1);
	i = -1;
	tmp = malloc(sizeof(char) * (new->tabarg[6] + 1));
	while (++i < new->tabarg[6])
		tmp[i] = new->str[i];
	tmp[i] = '\0';
	free(new->str);
	new->str = tmp;
	return (1);
}

int	prec_p(t_args *new)
{
	char	*tmp;
	int		i;
	int		j;

	if (new->tabarg[6] == -1 || ft_strlen(new->str) - 2 >= new->tabarg[6])
		return (1);
	tmp = malloc(sizeof(char) * (new->tabarg[6] + 3));
	tmp[0] = '0';
	tmp[1] = 'x';
	i = 1;
	while (++i < (new->tabarg[6] + 2) - (ft_strlen(new->str) - 2))
		tmp[i] = '0';
	j = 1;
	while (new->str[++j] != '\0')
		tmp[i++] = new->str[j];
	tmp[i] = '\0';
	free(new->str);
	new->str = tmp;
	return (1);
}

int	diesirae(t_args *new, char a)
{
	if (new->str[0] == '\0' || (new->str[0] == '0' && new->str[1] == '\0'))
		return (1);
	new->str = ft_stradd(new->str, a, 0);
	new->str = ft_stradd(new->str, '0', 0);
	return (1);
}

int	diesirae_0(t_args *new, char a)
{
	if (new->str[0] == '\0' || (new->str[0] == '0' && new->str[1] == '\0'))
		return (1);
	if (new->str[1] == '0' && new->str[0] == '0')
	{
		new->str[1] = a;
	}
	else if (new->str[0] == '0')
	{
		new->str[0] = a;
		new->str = ft_stradd(new->str, '0', 0);
	}
	else
	{
		new->str = ft_stradd(new->str, a, 0);
		new->str = ft_stradd(new->str, '0', 0);
	}
	return (1);
}
