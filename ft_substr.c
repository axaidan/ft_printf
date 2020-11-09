#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= len)
		len = 0;
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (s[i] && i - start < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}
