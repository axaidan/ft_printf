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

double	roundup(double d, int afterpoint)
{
	double		f_p;
	int			sign;
	int			i;
	int			j;
	double		pow;
	double		d_temp;
	long long	relevant;

	sign = (d < 0) ? -1 : 1;
	d = (d < 0) ? -d : d;
	f_p = d - (long long)d;
	i = 0;
	while (i < afterpoint + 1)
	{
		f_p = f_p - (long long)f_p;
		f_p *= 10;
		if (i == afterpoint)
		{
			relevant = (long long)f_p % 10;
			printf("\n\trelevt\t=\t%lld\n\ti\t=\t%d\n", relevant, i);
		}
		i++;
	}
	pow = 1;
	while (--i)
		pow *= 10;
	if (relevant >= 5)
	{
		d += 1 / pow;
		printf("\tadd\t=\t%.*f\n", afterpoint + 1, 1 / pow);
		printf("\t(d_temp == d)\t=\t%d\n", d_temp == d);
	}
	return (d * sign);
}

double	roundup_p_zero(double d)
{
	int		sign;
	double	f_p;
	double	temp;
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
