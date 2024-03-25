include "fdf.h"

//leer una linea;
//grabar esa linea en dim y medir el width;
//al mismo tiempo que la cuento ir grabandola a derechas en el t_coors right;
// hacer ingenieria de punteros para ir grabando los down, que sera en funcion del width; muy probablemente tener el puntero de la row anterio e ir iterandolo al mimo tiempo 
// la ingenieria de punteros consiste en simepre tener el primero de la NUEVA fila guardado, ademas tener otros 2 punteros en hilera recorriendose juntos para ir asignando el down;
// tener el  z_min y el z_max actualizandose con cada atoi 

//coors[0] = para guardar la referencia del primer nodo de former-row y poder seguir iterando renombrando current-row  con former-row
//coors[1] = esta es former-row(iterable) y graba el down con new-row
//coors[2] =  esta es new-row (iterable) y graba derecha

void set_row(t_map **map, char *line)
{
  static int    i;
  int j;
  static t_coors *former_row_reference;
  t_coors *former_row = NULL;

  j = 0;
  while(*line != '\n' || *line != '\0')
  {
    //el maps asi esta mal pensado
    map->coors[i][j]->height = atoi(&line);
    map->coors[i][j]->color  = atoi_color(&line);
    while (*line == ' ')
      *line++;
    j++;
  }
  i++;
}

void parser(t_fdf **fdf, char *map_file)
{
  t_dim *dim;
  int fd;
  char *line;

  fd = open(map_file)
  if (fd == -1)
      exit (1);
  while (1)
  {
    line = get_next_line(fd);
    if (!line)
      break;
    if (!check_row_syntax(line))
      exit(2);
    dim->width = set_row_width(line);
    dim = dim->next;
    set_row(&((*fdf)->map), line);
    free(line);
  }
}

