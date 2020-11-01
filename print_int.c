/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:34:09 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/01 19:44:26 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*precise_int(t_substr conv)
{
	int		i;
	int		neg;
	int		digits;
	char	*temp;

	digits = (conv.sub[0] == '-') ? ft_strlen(conv.sub) - 1 : ft_strlen(conv.sub);
	neg = (conv.sub[0] == '-') ? 1 : 0;
	if (conv.preci < 0 || digits >= conv.preci)
		return (conv.sub);
	if (conv.preci >= 0)	// SUPERFLU
	{
		temp = malloc(sizeof(char) * (neg + conv.preci + 1));		// NEEDS PROTECTION
		i = 0;
		if (neg)
			temp[i++] = '-';
		while (digits++ < conv.preci)
			temp[i++] = '0';
		while (conv.sub[neg])
			temp[i++] = conv.sub[neg++];
		temp[i] = 0;
		free(conv.sub);
		conv.sub = temp;
	}
	return (conv.sub);
}

char	*zero_pad_int(t_substr conv)
{
	int		i;
	int		neg;
	int		base_len;
	char	*temp;

	base_len = ft_strlen(conv.sub);
	neg = (conv.sub[0] == '-') ? 1 : 0;
	if (base_len >= conv.width)
		return (conv.sub);
	temp = malloc(sizeof(char) * (base_len + 1));	// NEEDS PROTECTION
	i = 0;
	if (conv.sub[i] == '-')
		temp[i++] = '-';
	while (base_len++ < conv.width)
		temp[i++] = '0';
	while (conv.sub[neg])
		temp[i++] = conv.sub[neg++];
	temp[i] = 0;
	free(conv.sub);
	conv.sub = temp;
	return (conv.sub);
}

int		print_int(t_substr conv, va_list args)
{
	//int		len;
	//int		digits;
	int		int_len;
	int		j;
	int		i;

	if (!(conv.sub = ft_itoa((conv.i = va_arg(args, int)))))
		return (-1);
	if (conv.preci == 0 && conv.i == 0)
	{
		free(conv.sub);
		return (0);	
	}
	conv.sub = (conv.f_zero) ? zero_pad_int(conv) : precise_int(conv); 	// MALLOC PROTECTION 
																		// CONTINUES HERE
	/*
	   if (conv.f_zero)
	   conv.sub = zero_pad_int(conv);
	   else
	   conv.sub = precise_int(conv);
	   */
	int_len = (int)ft_strlen(conv.sub);
	int_len = (int_len < conv.preci) ? conv.preci : int_len;
	j = 0;
	if (!(conv.f_minus) && !(conv.f_zero))
		while (j < conv.width - int_len)
			j += putchar_ret(' ');
	i = 0;
	while (conv.sub[i])
		ft_putchar_fd(conv.sub[i++], 1);
	if (conv.f_minus && !(conv.f_zero))
		while (i + j < conv.width)
			j += putchar_ret(' ');
	// FIXING MEMORY LEAKS, "if" PROBABLY USELESS
	if (conv.sub)
		free(conv.sub);
	return (i + j);
}

int		print_unsigned_int(t_substr conv, va_list args)
{
	int		int_len;
	int		j;
	int		i;

	if (!(conv.sub = utoa((conv.u = va_arg(args, unsigned int)))))
		return (-1);
	if (conv.preci == 0 && conv.u == 0)
	{
		free(conv.sub);
		return (0);
	}
	conv.sub = (conv.f_zero) ? zero_pad_int(conv) : precise_int(conv);
	int_len = (int)ft_strlen(conv.sub);
	int_len = (int_len < conv.preci) ? conv.preci : int_len;
	j = 0;
	if (!(conv.f_minus) && !(conv.f_zero))
		while (j < conv.width - int_len)
			j += putchar_ret(' ');
	i = 0;
	while (conv.sub[i])
		ft_putchar_fd(conv.sub[i++], 1);
	if (conv.f_minus && !(conv.f_zero))
		while (i + j < conv.width)
			j += putchar_ret(' ');
	// FIXING MEMORY LEAKS
	if (conv.sub)
		free(conv.sub);
	return (i + j);
}
