/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:44:47 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/24 14:11:07 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_char(t_substr conv, va_list args, char c)
{
	int	i;

	// SHOULD BE UNSIGNED CHAR, putchar_ret() TAKES CHARS FOR NOW
	conv.c = (c == '%') ? '%' : (unsigned char)va_arg(args, int);
	i = 0;
	if (!(conv.f_minus))
		while (i < conv.width - 1)
			i += (conv.f_zero) ? putchar_ret('0') : putchar_ret(' ');
	i += putchar_ret(conv.c);
	if (conv.f_minus)
		while (i < conv.width)
			i += putchar_ret(' ');
	return (i);
}
