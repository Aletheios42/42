#include<unistd.h>

void ft_putchar(int nb)
{
		write(1, &nb, 1);
}	
void	ft_print_combn(int n)
{
	int	nb;

	nb = 0;
		while (nb < (10^n))
		{
			nb++;
			ft_putchar(nb / 10);
			ft_putchar(nb % 10);
		}
}

int main(void)
{
	ft_print_combn(3);
}
