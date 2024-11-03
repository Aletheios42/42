/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:53:06 by alepinto          #+#    #+#             */
/*   Updated: 2023/07/11 10:52:11 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	row;

	row = -1;
	while (matrix[++row])
		free(matrix[row]);
	free(matrix);
}
