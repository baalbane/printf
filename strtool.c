/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 18:08:46 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/29 14:48:24 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_stradd(char *s1, char a, int id)
{
	char	*str;
	int		i;
	int		j;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	i = 0;
	j = 0;
	if (isnumberwithsign(s1) && a == '0')
		str[i++] = s1[j++];
	if (id == 0)
		str[i++] = a;
	while (s1[j])
		str[i++] = s1[j++];
	if (id == 1)
		str[i++] = a;
	str[i] = '\0';
	free(s1);
	return (str);
}

int		isnumberwithsign(char *s1)
{
	if (*s1 != '+' && *s1 != '-')
		return (0);
	if (*s1)
		s1++;
	while (*s1 != '\0')
	{
		if (*s1 < '0' || *s1 > '9')
			return (0);
		s1++;
	}
	return (1);
}

char	*writenull(void)
{
	char	*new;

	new = malloc(sizeof(char) * 7);
	new[0] = '(';
	new[1] = 'n';
	new[2] = 'u';
	new[3] = 'l';
	new[4] = 'l';
	new[5] = ')';
	new[6] = '\0';
	return (new);
}

int		ft_strlennbr(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	if (a[0] == '-' || a[0] == '+')
		i--;
	return (i);
}

char	*ft_strcpy(char *a)
{
	char	*new;
	int		i;

	if (a == NULL)
		return (NULL);
	i = -1;
	new = malloc(sizeof(char) * (ft_strlen(a) + 1));
	while (a[++i])
		new[i] = a[i];
	new[i] = '\0';
	return (new);
}
