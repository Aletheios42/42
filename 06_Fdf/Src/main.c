#include "../include/fdf.h"

static int	expose_handle(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
  {
	  init_fdf(&fdf);
    parser(&(fdf->map), av[1]);
    init_cam(&(fdf->cam));
	  render(fdf);
	  mlx_key_hook(fdf->win, &key_handle, fdf);
	  mlx_expose_hook(fdf->win, &expose_handle, fdf);
	  mlx_loop(fdf->mlx);
  }
  return (0);
}

static int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
