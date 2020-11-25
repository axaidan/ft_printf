/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <axaidan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:52:56 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/25 13:36:27 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_conv		init_struct(void)
{
	t_conv	conv;

	conv.i = 0;
	conv.c = 0;
	conv.str = NULL;
	conv.ptr = NULL;
	conv.width = 0;
	conv.preci = -1;
	conv.f_zero = 0;
	conv.f_minus = 0;
	conv.sub = NULL;
	return (conv);
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
