/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:39:02 by axaidan           #+#    #+#             */
/*   Updated: 2020/10/14 14:18:15 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		conv_key(char c)
{
	char	*conv_keys;
	int		i;

	conv_keys = "cspdiuxX%";
	i = 0;
	while (conv_keys[i] && conv_keys[i] != c)
		i++;
	if (conv_keys[i] == '\0')
		return (-1);
	return (i);
}

t_substr	init_struct(t_substr sub)
{
	sub.i = 0;
	sub.c = 0;
	sub.str = NULL;
	sub.ptr = NULL;
	sub.width = 0;
	sub.preci = -1;
	sub.f_zero = 0;
	sub.f_minus = 0;
	sub.sub = NULL;
	return (sub);
}

t_substr	parse_conv(t_substr substr, const char **fmt)
{
	while ((**fmt == '-' && !(substr.f_minus)) || (**fmt == '0' && !(substr.f_zero)))
	{
		if (**fmt == '-')
		{
			substr.f_minus = 1;
			substr.f_zero = 0;
		}
		if (**fmt == '0' && !(substr.f_minus))
			substr.f_zero = 1;
		(*fmt)++;
	}
	while (ft_isdigit(**fmt))
		substr.width = substr.width * 10 + *((*fmt)++) - '0';
	if (**fmt == '.')
	{
		substr.preci = 0;
		substr.f_zero = 0;
		(*fmt)++;
	}
	while (ft_isdigit(**fmt))
		substr.preci = substr.preci * 10 + *((*fmt)++) - '0';
	return (substr);
}

int		convert(const char **fmt, va_list args)
{
	t_substr	substr;
	int			printed;
	int			conversion;
	char		*str;

	substr = init_struct(substr);
	substr = parse_conv(substr, fmt); 
	display_struct(substr);
	if (**fmt == 'c')
		ft_putchar_fd((char)(substr.c = va_arg(args, int)), 1);
	else if (**fmt == 's')
		ft_putstr_fd((substr.str = va_arg(args, char *)), 1);
	else if (**fmt == 'd' || **fmt == 'i')
		ft_putnbr_fd((substr.i = va_arg(args, int)), 1);
	return (printed);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;
	const char	*temp;
	int			printed;

	va_start(args, fmt);
	printed = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			printed++;
		}
		else 
		{
			fmt++;
			printed += convert(&fmt, args);
		}
		fmt++;
	}
	va_end(args);
	return (printed);
}
