#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av)
{
    if (ac == 2 || ac == 3 || ac == 4)
   	{
        int cantidad;
        int numeroAleatorio;
        int min;
        int max;
        int i;
    	
        srand(time(NULL));
        if (av[2])
    	    min = atoi(av[2]);
    	else
            min = -2147483648;
        if (av[3])
            max = atoi(av[3]);
        else
            max = 2147483647;
        if (av[1])
        {
            cantidad = atoi(av[1]);
		    i = 0;
		    while (i++ < cantidad)
		    {
        	    numeroAleatorio = rand() % (max - min + 1) + min;
        	    printf("%d ", numeroAleatorio);
		    }
        }
        else
            printf("How many number to print?");
	}
    return (EXIT_SUCCESS);
}

