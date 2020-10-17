#include "libft.h"

int		putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

int		putstr_ret(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i += putchar_ret(s[i]);
	return (i);
}
