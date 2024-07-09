/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:11:53 by alepinto          #+#    #+#             */
/*   Updated: 2023/02/21 00:19:09 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, (power - 1)));
}

/*int main(void);
{
	int	nb;
	int	power;

	nb = 7;
	power = 3;
	ft_recursive_power(nb,  power);
	printf("%d", ft_recursive_power(nb. power));
	return (0);
}*/
