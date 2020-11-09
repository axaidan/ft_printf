#include "libft.h"

static int	overlaps(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src + i == dest)
			return (1);
		i++;
	}
	return (0);
}

// IF BOTH SRC & DST ARE NULL, RETURN NULL

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	// SRC=NULL && DST ==NULL SEGFAULTS ON LINUX, NOT ON MACOS
	if (!src && !dest)
		return (NULL);
	if (overlaps(dest, src, n))
	{
		i = n - 1;
		while (i > 0)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i--;
		}
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dest);
}
