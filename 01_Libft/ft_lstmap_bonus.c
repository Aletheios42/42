/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:36:11 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/07 14:29:28 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newel;
	t_list	*cont;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	cont = NULL;
	while (lst)
	{
		cont = f(lst->content);
		newel = ft_lstnew(cont);
		if (!cont)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newel);
		lst = lst->next;
	}
	return (newlst);
}
