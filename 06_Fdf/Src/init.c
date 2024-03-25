#include "../include/fdf.h"

void init_fdf(t_fdf **fdf)
{
	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!*fdf)
		return ;
	(*fdf)->mlx = mlx_init();
	(*fdf)->win = mlx_new_window((*fdf)->mlx, (*fdf)->win_x, (*fdf)->win_y, WINDOW_NAME);
  (*fdf)->image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	(*fdf)->buffer = mlx_get_data_addr((*fdf)->image, &((*fdf)->pixel_bits), \
			&((*fdf)->line_bytes), &((*fdf)->endian);
}

t_map	*init_map(void)
{
	t_map	*map;:warn("%s");

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	}

t_cam	*init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WINDOW_WIDTH / 2;
	cam->move_y = WINDOW_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

t_line	*init_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = max((fdf->map->max_z - fdf->map->min_z), \
		max(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
