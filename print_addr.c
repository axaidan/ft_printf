/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:36:27 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/01 18:48:18 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * no .f_zero
 * no .preci
 */
static char	*make_addr_str(t_substr conv, va_list args)
{
	char			*temp;
	unsigned long	addr;

	addr = (unsigned long)va_arg(args, void *);	
	if (!addr)
	{
		if (!(conv.sub = ft_strdup("(nil)")))
			return (NULL);
	}
	else
	{
		if (addr > 4294967295)
			conv.sub = ltox(addr, 'x');
		else
			conv.sub = utox((unsigned int)addr, 'x');
		if (!(conv.sub))
			return (NULL);
		temp = conv.sub;
		if (!(conv.sub = ft_strjoin("0x", conv.sub)))
			return (NULL);
		free(temp);
	}
	return (conv.sub);
}

int			print_addr(t_substr conv, va_list args)
{
	int		len;
	int		i;
	int		j;

	if (!(conv.sub = make_addr_str(conv, args)))
		return (-1);
	len = (int)ft_strlen(conv.sub);
	j = 0;
	if (!(conv.f_minus))
		while (j < conv.width - len)
			j += putchar_ret(' ');
	i = putstr_ret(conv.sub); 
	if (conv.f_minus)
		while (i + j < conv.width)
			j += putchar_ret(' ');
	// FIXING LEAKS, "if" PROBABLY USELESS
	if (conv.sub)
		free(conv.sub);
	return (i + j);
}
