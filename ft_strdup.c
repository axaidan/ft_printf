/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:48:04 by axaidan           #+#    #+#             */
/*   Updated: 2020/09/25 17:48:06 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;

// SHOULD SEGFAULT WITH NULL PARAM
//	if (s == NULL)
//		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(copy = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i]) 
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
