#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>


typedef struct s_input
{
  long philosophers;
  long time_to_die;
  long time_to_eat;
  long time_to_sleep;
  long meals_cap;
} t_input;

typedef struct s_fork
{
  pthread_mutex_t fork;
  bool            taken;
  struct s_fork   *next;
} t_fork;

typedef struct s_philo
{
  int id;
  long meals_counter;
  bool full;
  long last_meal_time;
  t_fork *left_fork;
  t_fork *right_fork;
  struct s_philo *right;
} t_philo;

bool parser(t_input **, char **av, int ac);
void print_error(const char *error);
long ft_philo_atol(char *nbr);


#endif 
