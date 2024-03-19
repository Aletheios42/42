#include "philo.h"


void print_error(const char* error)
{
  printf("%s\n", error);
  exit(1);
}

bool  parser(t_input **input, char **av, int ac)
{
  (*input)->philosophers = ft_philo_atol(av[1]);
  if ((*input)->philosophers== -1)
    return (0);
  (*input)->time_to_die = ft_philo_atol(av[2]);
  if ((*input)->time_to_die == -1)
    return (0);
  (*input)->time_to_eat = ft_philo_atol(av[3]);
  if ((*input)->time_to_eat == -1)
    return (0);
  (*input)->time_to_sleep = ft_philo_atol(av[4]);
  if ((*input)->time_to_sleep == -1)
    return (0);
  if (ac == 5)
    (*input)->meals_cap = 0;
  else if (ac == 6)
  {
      (*input)->meals_cap = ft_philo_atol(av[5]);
      if ((*input)->meals_cap == -1)
          return (0);
  }
  return (1);
}

long  ft_philo_atol(char *nbr)
{
  long result = 0;
  int   i = -1;
  while(nbr[++i] == ' ')
    i++;
  while(nbr[i] >= '0' && nbr[i] <= '9') {
    result = result * 10 + (nbr[i] - '0');
    i++;
  }
  if(nbr[i] != '\0' || result > INT_MAX || result < INT_MIN)
    return (-1);
  return (result);
}

int main(int ac, char **av)
{
  t_input *input = NULL;

  if (ac == 5 || ac == 6)
  {
    input = (t_input *)malloc(sizeof(t_input));
    if (!input)
      return (print_error("Malloc error"),0);
    if (!parser(&input, av, ac)) { 
        free(input);
        print_error("Bad Syntax");
    }
    //todo el philo xD
  }
  return (0);
}
