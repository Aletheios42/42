#include "fdf.h"

void set_row(t_coors **coors, char *line)
{
  t_row *current_row = NULL;

  while (*line != '\n' && *line != '\0')
  { 
    if (!init_row(&current_row))
      return ;
    current_row = set_data(line)
    current_row = current_row->right;
    while (*line != ' ')
      line++;
  }
  (*coors)->row = current_row;
}

void parser(t_fdf **fdf, char *map_file)
{
  t_map *datamap = NULL;
  t_coors *datacoors = NULL;
  char *line = NULL;
  int fd;

  fd = open(map_file)
  if (fd == -1)
      exit (1);
  init_map(datamap);
  while (1)
  {
    line = get_next_line(fd);
    if (!line)
      break;
    init_coors(&datacoors);
    set_row(datamap->coors, line);
    datamap->coors = datamap->coors->next;
    free(line);
  }
  (*fdf)->map = datamap;
  close(fd);
}

