#ifndef PHILO.H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>


struct s_parse
{
  long philosophers;
  long time_to_die;
  long time_to_eat;
  long time_to_sleep;
  long meals_cap;
}

struct s_philo
{
  int id;
  long meals_counter;
  bool full;
  long last_meal_time;
  t_fork *left_fork;
  t_fork *right_fork;
}
struct s_fork
{
  pthread_mutex_t fork;
}
#endif // !PHILO.H


