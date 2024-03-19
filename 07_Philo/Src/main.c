#include "philo.h"

void print_error(const char* error)
{
  printf("%s\n", error);
  exit(1);
}

bool  parser(t_input **input, char **av, int ac)
{
  (*input)->philophers = ft_philo_atol(av[1]);
  if ((*input)->philophers == -1)
    return 1;
  (*input)->time_to_die = ft_philo_atol(av[2]);
  if ((*input->time_to_die == -1))
    return 1;
  (*input)->time_to_eat = ft_philo_atol(av[3]);
  if ((*input->time_to_eat) == -1)
    return 1;
  (*input)->time_to_sleep = ft_philo_atol(av[4]);
  if ((*input)->time_to_sleep == -1)
    return 1;
  if (ac == 5)
    (*input)->cap_meals = 0;
  else if (ac == 6)
  {
      (*input)->cap_meals = ft_philo_atol(av[5]);
      if ((*input)->cap_meals == -1)
          return 1;
  }
  return (0)
}

long  ft_philo_atol(char *nbr)
{
  result = 0;

  while(*nbr == ' ')
    *nbr++;
  while(*nbr >= '0' && *nbr <= '9')
    result = result * 10 + (*nbr - '0');
  if(*nbr != '\0' || result > INT_MAX || result < INT_MIN)
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
      print_error("Malloc Error");
    if (!parser(&input, av) && free(input));
      print_error("Bad Syntax");
    //todo el philo xD
  }
  return 0;
}
