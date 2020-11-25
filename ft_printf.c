/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:39:02 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/25 11:27:50 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_substr	parse_flags(t_substr substr, const char **fmt)
{
	while ((**fmt == '-' && !(substr.f_minus)) || (**fmt == '0'))
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
	return (substr);
}

t_substr	parse_width(t_substr substr, const char **fmt, va_list args)
{
	if (**fmt == '.')
	{
		substr.preci = 0;
		substr.f_zero = 0;
		(*fmt)++;
	}
	if (**fmt == '*')
	{
		substr.preci = va_arg(args, int);
		if (substr.preci < 0)
			substr.preci = -1;
		(*fmt)++;
	}
	else
		while (ft_isdigit(**fmt))
			substr.preci = substr.preci * 10 + *((*fmt)++) - '0';
	return (substr);
}

t_substr	parse_width(t_substr substr, const char **fmt, va_list args)
{
	if (**fmt == '*')
	{
		substr.width = va_arg(args, int);
		if (substr.width < 0)
		{
			substr.f_minus = 1;
			substr.f_zero = 0;
			substr.width = -substr.width;
		}
		(*fmt)++;
	}
	else
		while (ft_isdigit(**fmt))
			substr.width = substr.width * 10 + *((*fmt)++) - '0';
	return (substr);
}

int			convert(const char **fmt, va_list args)
{
	t_substr	substr;
	int			printed;

	printed = 0;
	substr = init_struct();
	substr = parse_flags(substr, fmt);
	substr = parse_preci(parse_width(substr, fmt, args), fmt, args);
	if (**fmt == 'c' || **fmt == '%')
		printed = print_char(substr, args, **fmt);
	else if (**fmt == 's')
		printed = print_str(substr, args);
	else if (**fmt == 'd' || **fmt == 'i')
		printed = print_int(substr, args);
	else if (**fmt == 'u')
		printed = print_unsigned_int(substr, args);
	else if (**fmt == 'x' || **fmt == 'X')
		printed = print_hexa(substr, args, **fmt);
	else if (**fmt == 'p')
		printed = print_addr(substr, args);
	else
		return (-1);
	return (printed);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			printed;
	int			ret;

	va_start(args, fmt);
	printed = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			printed += putchar_ret(*fmt);
		else
		{
			fmt++;
			if ((ret = convert(&fmt, args)) < 0)
			{
				va_end(args);
				return (-1);
			}
			printed += ret;
		}
		fmt++;
	}
	va_end(args);
	return (printed);
}
