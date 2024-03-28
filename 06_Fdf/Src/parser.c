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



void set_row(t_coors **coors, char *line)
{
  t_row *current_row;

  while (*line != '\n' && *line != '\0')
  {
    current_row = (t_row *)malloc(sizeof(t_row));
    if (!current_row)
      return (NULL);
    current_row->right = NULL;
    current_row->height = 0;
    current_row->color = 0;
    current_row = set_data(line)
    current_row = current_row->right;
    while (*line != ' ')
      line++;
  }
  coors->row = current_row;
}

void parser(t_fdf **fdf, char *map_file)
{
  t_dim *dim;
  t_map *datamap;
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
    set_row(datamap->coors, line);
    datamap->coors = datamap->coors->next;
    free(line);
  }
  (*fdf)->map = datamap;
}

