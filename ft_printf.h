/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:59:11 by axaidan           #+#    #+#             */
/*   Updated: 2020/11/25 18:57:22 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_conv
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
}				t_conv;

int				print_int(t_conv conv, va_list args);
char			*utoa(unsigned int n);
int				print_unsigned_int(t_conv conv, va_list args);

int				print_char(t_conv conv, va_list args, char c);

int				print_str(t_conv conv, va_list args);

char			*utox(unsigned int n, char c);
int				print_hexa(t_conv conv, va_list args, char c);

char			*ltox(unsigned long n, char c);
int				print_addr(t_conv conv, va_list args);

t_conv			init_struct(void);
int				putchar_ret(char c);
int				putstr_ret(char *s);
void			ft_putchar_fd(char c, int fd);
int				ft_isdigit(int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
char			*ft_itoa(int x);
size_t			ft_strlen(const char *s);
int				ft_printf(const char *fmt, ...);

#endif
