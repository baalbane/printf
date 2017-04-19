/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:45:10 by baalbane          #+#    #+#             */
/*   Updated: 2016/09/20 19:21:36 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prints(va_list *arg, t_args *new)
{
	if (new->tabarg[7] == 2)
		printwchars(arg, new);
	else
		new->str = ft_strcpy(va_arg(*arg, char*));
	if (new->str == NULL)
		new->str = writenull();
	return (1);
}

char	*addwchar(char *str, char *new)
{
	char	*ptr;

	ptr = new;
	while (*new != '\0')
	{
		str = ft_stradd(str, ft_atoibase(new, 2), 1);
		while (*new != '\0' && *new != ' ')
			new++;
		if (*new == ' ')
			new++;
	}
	free(ptr);
	return (str);
}

char	*do_mask(char *str)
{
	int		tmp;
	int		len;
	char	*str2;

	tmp = ft_strlen(str);
	if (tmp <= 7)
		str2 = ft_strcpy("0xxxxxxx");
	else if (tmp <= 11)
		str2 = ft_strcpy("110xxxxx 10xxxxxx");
	else if (tmp <= 16)
		str2 = ft_strcpy("1110xxxx 10xxxxxx 10xxxxxx");
	else
		str2 = ft_strcpy("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	len = ft_strlen(str2);
	while (len-- > 0)
	{
		if (str2[len] == 'x' && tmp > 0)
			str2[len] = str[--tmp];
		else if (str2[len] == 'x')
			str2[len] = '0';
	}
	free(str);
	return (str2);
}

int		printwchars(va_list *arg, t_args *new)
{
	wchar_t	*tmp;

	if (!(tmp = va_arg(*arg, wchar_t*)))
	{
		new->str = writenull();
		return (1);
	}
	new->str = malloc(sizeof(char));
	new->str[0] = '\0';
	while (*tmp != '\0')
	{
		new->str = addwchar(new->str, do_mask(ft_itoabase(*tmp, 2)));
		tmp++;
	}
	return (1);
}
