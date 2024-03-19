#include "philo.h"

void print_error(const char* error)
{
  printf("%s\n", error);
  exit(1);
}

void  parser(t_input **input, char **av, int ac)
{
  (*input)->philophers = ft_philo_atol(av[1]);
  (*input)->time_to_die = ft_philo_atol(av[2]);
  (*input)->time_to_eat = ft_philo_atol(av[3]);
  (*input)->time_to_sleep = ft_philo_atol(av[4]);
  if (ac == 5)
    (*input)->cap_meals = 0;
  else if (ac == 6)
      (*input)->cap_meals = ft_philo_atol(av[5]);

}

void  init_input(t_input **input)
{
  *(input) = (t_input *)malloc(sizeof(t_input));
  if (!*input)
    print_error("Malloc Error\n");
}

long  ft_philo_atol(char *nbr)
{
  result = 0;

  while(*nbr == ' ')
    *nbr++;
  while(*nbr >= '0' && *nbr <= '9')
    result = result * 10 + (*nbr - '0');
  if(*nbr != '\0' || result > INT_MAX || result < INT_MIN)
    print_error("INVALID INPUT");
  return (result);
}

int main(int ac, char **av)
{
  t_input *input = NULL;

  if (ac == 5 || ac == 6)
  {
    init_input(&input);
    parser(&input, av);
  }
}
