#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		n;
	double	nd;
	double	phi;
	int 	tot;

	tot = 610;
	if (ac == 2)
	{
        int total = atoi(av[1]);
		phi = (sqrt(5) - 1) / 2 * tot;
		nd = phi;
		n = - 1;
		printf("\n");
		while (++n < total)
		{
			printf("%i ", (int)nd);
			nd+= phi;
			if (nd > tot)
				nd -= tot;
		}
		printf("\n");
	}
	return (0);
}