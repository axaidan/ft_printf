#include "libft.h"

static int	is_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find_end(char const *s, char const *set, int i)
{
	int	end;

	while (s[i])
	{
		while (!(is_set(s[i], set)) && s[i])
			i++;
		end = i;
		while (is_set(s[i], set) && s[i])
			i++;
	}
	return (end);
}

char		*ft_strtrim(char const *s, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && is_set(s[start], set))
		start++;
	end = (s[start] == '\0') ? start : find_end(s, set, start);
	if (!(trimmed = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		trimmed[i] = s[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}