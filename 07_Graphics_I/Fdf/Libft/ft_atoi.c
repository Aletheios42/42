/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:40:03 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/07 12:47:46 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isspace(char c) {
  if (c == 32)
    return (1);
  if (c == '\n')
    return (1);
  if (c == '\t')
    return (1);
  if (c == '\r')
    return (1);
  if (c == '\v')
    return (1);
  if (c == '\f')
    return (1);
  return (0);
}

int ft_atoi(const char *str) {
  int result;
  int i;
  int flag;

  result = 0;
  i = 0;
  flag = 1;
  while (ft_isspace(str[i]))
    i++;
  if (str[i] == '+' || str[i] == '-') {
    if (str[i] == '-')
      flag *= -1;
    i++;
  }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
    result = result * 10 + str[i] - '0';
    i++;
  }
  return (result * flag);
}
