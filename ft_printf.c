/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:39:02 by axaidan           #+#    #+#             */
/*   Updated: 2020/10/17 16:26:55 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * initializes the structure before each conversions
 * precision initialized to -1 to signal it was not set at all, to 0 for example
 */
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

/*
 * sets f_zero and f_minus, ignores f_zero if f_minus present
 * what should I do if more than one of those flags ? 
 */
t_substr	parse_flags(t_substr substr, const char **fmt)
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
	return (substr);
}

/*
 * sets width and precision
 * ignores f_zero if precision present
 */
t_substr	parse_fields(t_substr substr, const char **fmt, va_list args)
{
	if (**fmt == '*')
	{
		substr.width = va_arg(args, int);
		(*fmt)++;
	}
	else
		while (ft_isdigit(**fmt))
			substr.width = substr.width * 10 + *((*fmt)++) - '0';
	if (**fmt == '.')
	{
		substr.preci = 0;
		substr.f_zero = 0;
		(*fmt)++;
	}
	if (**fmt == '*')
	{
		substr.preci = va_arg(args, int);
		(*fmt)++;
	}
	else
		while (ft_isdigit(**fmt))
			substr.preci = substr.preci * 10 + *((*fmt)++) - '0';
	return (substr);
}

int		convert(const char **fmt, va_list args)
{
	t_substr	substr;
	int			printed;

	substr = parse_fields(parse_flags(init_struct(substr), fmt), fmt, args);
	// SHOULD ADD AN ERROR CASE IF .preci or .width < 0
	// 		NOT POSSIBLE FOR THE MOMENT
	// 	OR IF 
	/*
	   substr = init_struct(substr);
	   substr = parse_flags(substr, fmt); 
	   substr = parse_fields(substr, fmt, args);
	   */
	//display_struct(substr);
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
	if (substr.sub)
		free(substr.sub);
	return (printed);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			printed;
	int			ret;

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
			fmt++;	// SKIP '%'
			if ((ret = convert(&fmt, args)) < 0)
				return (-1);
			printed += ret;
		}
		fmt++;
	}
	va_end(args);
	return (printed);
}
