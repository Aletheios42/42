
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# include "keys.h"
# include "colors.h"

typedef struct s_row {
    int height;
    int color;
    void *right;
} t_row;

typedef struct s_coors {
    t_row row;
    void *next;
} t_coors;

typedef struct s_map {
    t_coors *coors;
    int *columns;
    int rows;
    int max_z;
    int min_z;
} t_map;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

typedef struct s_cam
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

typedef struct s_fdf
{
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_cam	*cam;
	t_map	*map;
}	t_fdf;

#endif
