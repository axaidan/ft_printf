/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <axaidan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:52:56 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/25 11:28:19 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_substr	init_struct(void)
{
	t_substr	sub;

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

int			putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

int			putstr_ret(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i += putchar_ret(s[i]);
	return (i);
}
