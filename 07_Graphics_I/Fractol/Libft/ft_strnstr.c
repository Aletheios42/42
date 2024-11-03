/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:28:30 by alepinto          #+#    #+#             */
/*   Updated: 2023/03/15 12:51:51 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && ((i + j) <= len - 1))
		{
			j++;
			if (j == ft_strlen(needle))
				return ((char *)(haystack + i));
		}
		i++;
		j = 0;
	}
	return (0);
}
