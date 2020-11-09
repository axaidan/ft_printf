/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:30:09 by axaidan           #+#    #+#             */
/*   Updated: 2020/09/25 18:46:17 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(mapped = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped[i] = (*f)(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
