/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:40:02 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/07 00:43:28 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	row;

	row = 0;
	while (matrix[row])
		row++;
	while (--row >= 0)
		free(matrix[row]);
	free(matrix);
}
