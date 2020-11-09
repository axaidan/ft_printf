/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:32:40 by axaidan           #+#    #+#             */
/*   Updated: 2020/10/12 16:39:52 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	start = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new); 
		lst = lst->next;
	}
	return (start);
}

// A GARDER DE COTE 
// CREE UNE NOUVELLE LISTE SANS LES ELEMENTS QUI ONT RETURN NULL EN PASSANT PAR (*F)
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*new;
	t_list	*start;
	void	*new_data;

	new = NULL;
	prev = NULL;
	start = NULL;
	while (lst)
	{
		if ((new_data = (*f)(lst->content)))
		{
			if (!(new = malloc(sizeof(t_list))))
				return (NULL);
			if (!(start))
				start = new; 
			if (prev)
				prev->next = new;
			new->content = new_data;
			new->next = NULL;
			prev = new;
		}
		lst = lst->next;
	}
	return (start);
}
*/
