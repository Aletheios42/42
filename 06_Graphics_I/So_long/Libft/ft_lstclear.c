/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:37:29 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/07 13:13:29 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	*lst = NULL;
	while (ptr != NULL)
	{
		next = ptr->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = next;
	}
}
