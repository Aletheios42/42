/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:48 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/09 17:41:15 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (BONUS == 0 && argc == 5)
		pipex(argv, env);
	else if (BONUS == 1 && argc >= 5)
		pipex_bonus(argc, argv, env);
	else
		ft_putendl_fd("INVALID ARGUMENTS", 2);
	return (0);
}
