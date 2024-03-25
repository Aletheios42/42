#include "../include/fdf.h"

static int	expose_handle(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	init_fdf(&fdf);
	render(fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
}

static int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
