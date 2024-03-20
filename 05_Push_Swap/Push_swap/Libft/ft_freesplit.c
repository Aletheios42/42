/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:44:00 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/07 00:44:02 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_freesplit(char **matrix, int row)
{
	if (!matrix[row])
	{
		while (row--)
			free(matrix[row]);
		free(matrix);
		return (1);
	}
	return (0);
}
