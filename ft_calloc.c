#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (!(alloc = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(alloc, size * nmemb);
	return (alloc);
}
