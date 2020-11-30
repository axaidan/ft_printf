#include <stdio.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <axaidan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:48:00 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/27 19:34:23 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_relevant(double d, int afterpoint)
{
	double		f_p;
	int			i;
	int			relevant;

	d = (d < 0) ? -d : d;
	f_p = d - (long long)d;
	i = 0;
	while (i < afterpoint + 1)
	{
		f_p = f_p - (long long)f_p;
		f_p *= 10;
		if (i == afterpoint)
			relevant = (int)f_p % 10;
		i++;
	}
	if (relevant >= 5)
		return (relevant);
	else
		return (0);
}

void	shift_str(char **str)
{
	int		neg;
	char	*temp;
	char	*buf;

	temp = *str;
	neg = ((*str)[0] == '-') ? 1 : 0;
	buf = (neg) ? "-1" : "1";
	temp = ft_strjoin(buf, (*str) + neg);
	free(*str);
	*str = temp;
}

void	roundup_str(char **str, int i)
{
	if ((*str)[i] >= '0' && (*str)[i] <= '8')
		(*str)[i]++;
	else if ((*str)[i] == '9')
	{
		(*str)[i] = '0';
		roundup_str(str, i - 1);
	}
	else if ((*str)[i] == '.')
		roundup_str(str, i - 1);
	else if ((*str)[i] == '-' || i == -1)
		shift_str(str);
}

double	roundup_p_zero(double d)
{
	int		sign;
	double	f_p;
	int		relevant;

	sign = (d < 0) ? -1 : 1;
	d = (d < 0) ? -d : d;
	f_p = d - (long long)d;
	relevant = ((int)(f_p * 10)) % 10;
	if (relevant == 5)
		d = ((long long)d % 2 == 0) ? (long long)d : (long long)d + 1;
	else if (relevant > 5)
		d = (long long)d + 1;
	return (((double)d) * sign);
}

int		zero_is_signed(long double lf)
{
	return ((1.0 / lf) != (1.0 / ((lf < 0) ? 1 : 0)));
}