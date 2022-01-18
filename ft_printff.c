/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:59:17 by abonard           #+#    #+#             */
/*   Updated: 2022/01/18 18:22:18 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define GROSSE 10000
typedef	struct s_print
{
	long long int	nbr;
	va_list	args;
	int	wdt;
	int	prc;
	int	zero;
	int	dash;
	int	total_value;
	int	sign;
	int	sp;
} t_print;

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->sign = 0;
	tab->total_value = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_number(t_print *print)
{
	int	num;

	num = va_arg(print->args, int);
	ft_putnbr_fd(num, 1);
	return (1);

	//return (0) a rajouter plus tard 

}
void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int ft_string(t_print *print)
{
	char *str = NULL;

	str = va_arg(print->args, char *);
	ft_putstr_fd(str, 1);
	return (1);
}

int	ft_strlen_custom(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_putnbr_base(unsigned long long int nbr, char *base)
{
	int	size;
	unsigned long long int	nb;

	size = ft_strlen_custom(base);
	if (nb < 0)
	{
		nb = -nbr;
		ft_putchar_fd('-', 1);
	}
	else
		nb =  nbr;
	if (nb >= size)
	{
		ft_putnbr_base(nb / size, base);
		ft_putchar_fd(base[nb % size], 1);
	}
	else
		ft_putchar_fd(base[nb % size], 1);
}


int	ft_cest_quoi(t_print *print, const char fmt)
{
	if (fmt == 'i' || fmt == 'd')
		ft_number(print);
	else if (fmt == 'c')
	{
		char	c;
		c = va_arg(print->args, int);
		write(1, &c, 1);
	}
	else if (fmt == 's')
	{
		char *str;
		ft_string(print);
	}
	else if (fmt == 'p')
	{
		print->nbr = va_arg(print->args, unsigned long long int);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(print->nbr, "0123456789abcdef");
	}
	else if (fmt == 'u')
	{
		print->nbr = va_arg(print->args, unsigned  int);
		ft_putnbr_base(print->nbr, "0123456789");
	}
	else if (fmt == 'x' || fmt == 'X')
	{
		print->nbr = va_arg(print->args, unsigned long long  int);

		if (fmt == 'x')
			ft_putnbr_base(print->nbr, "0123456789abcdef");
		else
			ft_putnbr_base(print->nbr, "0123456789ABCDEF");
	}
	//else if (fmt == '%')
		//write(1, "%", 1);
	return (-1);
}

#include <stdio.h>

int	ft_printouf(const char *fmt, ... )
{
	int		i;
	t_print	print;

	i = 0;
	va_start(print.args, fmt);
	while (fmt && fmt[i])
	{
		if ((fmt[i - 1] == '%') && (i > 0))
		{
			if (fmt[i] == '%')
				write(1, "%", 1);
			ft_cest_quoi(&print, fmt[i]);
		}
		else if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
		}
		i++;
	}
	print.total_value = i;
	return (print.total_value);
	printf("%d", i);
}

#include <stdio.h>
int main()
{
	int a = 50;
	char *nice = "NICE!";
	int *pointer = &a;

	ft_printouf("je m'appel %s mon penis fait %d, c'est %s %%, je veux %u de banane et %x de chapeau et mon fils a %p putes, fuck %p\n", "BORAT", 17, "NICE", -2147483649, 157, nice, pointer);
	printf("je m'appel %s mon penis fait %d, c'est %s %%, je veux %u  de banane et %x de chapeau et mon fils a %p putes, fuck %p\n", "BORAT", 17, "NICE", -2147483649, 157, nice, pointer);

	return (0);
}
