/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:03:20 by axaidan           #+#    #+#             */
/*   Updated: 2020/10/18 13:25:28 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*precise_str(t_substr conv)
{
	int	i;
	int	len;

	len = ft_strlen(conv.str);
	len = (conv.preci < len) ? conv.preci : len ;
	if (!(conv.sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		conv.sub[i] = conv.str[i];
		i++;
	}
	conv.sub[i] = '\0';
	return (conv.sub);
}

int		print_str(t_substr conv, va_list args)
{
	int		len;
	int		printed;

	conv.str = va_arg(args, char*);
	if (!(conv.str) && !(conv.sub = ft_strdup("(null)")))
		return (-1);
	/*
	if (!(conv.str))
	{
		if (!(conv.sub = ft_strdup("(null)")))
			return (-1);
	}
	*/
	else
	{
		if (!(conv.sub = (conv.preci >= 0) ? precise_str(conv) : ft_strdup(conv.str)))
			return (-1);
	}
	len = (int)ft_strlen(conv.sub);
	printed = 0;
	if (!(conv.f_minus))
		while (printed < conv.width - len)
			printed += putchar_ret(' ');
	printed += putstr_ret(conv.sub);
	if (conv.f_minus)
		while (printed < conv.width)
			printed += putchar_ret(' ');
	return (printed);
}
