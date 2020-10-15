/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:59:11 by axaidan           #+#    #+#             */
/*   Updated: 2020/10/15 15:36:33 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__

# define __FT_PRINTF_H__

# include <stdarg.h>

# define CHAR	0
# define STR	1
# define PTR	2
# define INTD	3
# define INTI	4
# define UNS	5
# define HEXL	6
# define HEXU	7
# define PERC	8

typedef struct					s_substr
{
	int				i;
	unsigned int	u;
	char			c;
	char			*str;
	void			*ptr;
	int				width;
	int				preci;
	int				f_zero;
	int				f_minus;
	char			*sub;
}								t_substr;

/*
 * DEBUG
 */
void			display_struct(t_substr substr);

/*
 * INT AND UNSIGNED INT
 */
char			*precise_int(t_substr conv);
char			*zero_pad_int(t_substr conv);
int				print_int(t_substr substr, va_list args);
char			*utoa(unsigned int n);
int				print_unsigned_int(t_substr substr, va_list args);

/*
 * GENERAL
 */
int				ft_printf(const char *fmt, ...);

#endif
