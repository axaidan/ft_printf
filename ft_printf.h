/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:59:11 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/13 17:34:15 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include <stdarg.h>

typedef struct					s_substr
{
	int				i;
	unsigned int	u;
	unsigned char	c;
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
 * CHAR
 */
int				print_char(t_substr conv, va_list args, char c);

/*
 * STR
 */
int				print_str(t_substr conv, va_list args);

/*
 * HEXADECIMAL
 */
char			*utox(unsigned int n, char c);
int				print_hexa(t_substr conv, va_list args, char c);

/*
 * VOID *
 */
char			*ltox(unsigned long n, char c);
int				print_addr(t_substr conv, va_list args);

/*
 * GENERAL
 */
int				putchar_ret(char c);
int				putstr_ret(char *s);
int				ft_printf(const char *fmt, ...);

#endif
