#include "fdf.h"

void init_row(t_row **row)
{
  *row = (t_row *)malloc(sizeof(t_row));
  if (!*row)
    return ;
  (*row)->right = NULL;
  (*row)->height = 0;
  (*row)->color = 0;
}

void init_map(t_map **map)
{
  (*map) = (t_map *)malloc(sizeof(t_map));
  if (!*map)
    return ;
  (*map)->columns = NULL;
  (*map)->rows = 0;
  (*map)->max_z = 0;
  (*map)->min_z = 0;
}

void init_coors(t_coors **coors)
{
  *coors = (t_coors *)malloc(sizeof(t_coors));
  if (!*coors)
    return ;
  init_row(&((*coors)->row));
  (*coors)->next = NULL;
}
