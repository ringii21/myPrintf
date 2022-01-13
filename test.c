#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	nb;

	size = 0;
	//if (ft_check_base(base) == 0)
	//	return ;
	size = ft_strlen(base);
	if (nbr < 0)
	{
		nb = -nbr;
		ft_putchar('-');
	}
	else
		nb = nbr;
	if (nb >= size)
	{
		ft_putnbr_base(nb / size, base);
		ft_putchar(base[nb % size]);
	}
	else
		ft_putchar(base[nb % size]);
}
int main ()
{
	ft_putnbr_base(157, "0123456789abcdef");
	return 0;

}
