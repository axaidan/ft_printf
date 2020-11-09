/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:17:05 by axaidan           #+#    #+#             */
/*   Updated: 2020/09/25 18:22:41 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NOT PROTECTED IF YOU SEND NULL TO DEST OR SRC

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = ft_strlen((const char*)dest);
	len_s = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (len_d + i < size - 1 && src[i])
		{
			dest[len_d + i] = src[i];
			i++;
		}
		dest[len_d + i] = '\0';
	}
	// IF I HAVE ROOM TO ATTEMPT A COPY
	if (len_d < size)
		return (len_d + len_s); // RETURN LENGTH OF A CONCATENATION ATTEMPT
	// HERE len_d >= size ==> SO THERE IS NO SPACE
	return (size + len_s);		// RETURN OF A BUFFER[size] OVERFLOWING LENGTH OF CONCATENATION ATTEMPT
}
// RETURN OF STRLCAT GIVES YOU LENGTH OF CONCATENATED STRING IN CASE ANOTHER 
// CONCATENATION IS ON THE WAY
