/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:59:17 by abonard           #+#    #+#             */
/*   Updated: 2022/01/25 17:33:50 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define GROSSE 10000
typedef	struct s_print
{
	long long int	nbr;
	va_list			args;
	int				wdt;
	int				prc;
	int				zero;
	int				dash;
	int				total_value;
	int				sign;
	int				sp;
	char			buff[50000];
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
	bzero(tab->buff, 50000);
	return (tab);
}

int	ft_len_hexa(unsigned long long int nbr)
{
	int	len;

	len = 0;
	if ( nbr == 0)
		return (1);
	else if (nbr == -2147483648)
		return (11);
	else if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}


int	ft_len(unsigned long long int nbr)
{
	int	len;

	len = 0;
	if ( nbr == 0)
		return (1);
	else if (nbr == -2147483648)
		return (11);
	else if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_number(t_print *print)
{
	int	num;

	if (!print)
		return (0);
	num = va_arg(print->args, int);
	ft_putnbr_fd(num, 1);
	print->total_value += ft_len(num);
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

int	ft_strlen_custom(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return(i);
}

int ft_string(t_print *print)
{
	char *str = NULL;

	str = va_arg(print->args, char *);
	ft_putstr_fd(str, 1);
	print->total_value += ft_strlen_custom(str);
	return (1);
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
		print->total_value += 1;
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
		print->total_value += ft_len_hexa(print->nbr);
	}
	else if (fmt == 'u')
	{
		print->nbr = va_arg(print->args, unsigned  int);
		ft_putnbr_base(print->nbr, "0123456789");
		print->total_value += ft_len(print->nbr);
	}
	else if (fmt == 'x' || fmt == 'X')
	{
		print->nbr = va_arg(print->args, unsigned long long  int);

		if (fmt == 'x')
		{
			ft_putnbr_base(print->nbr, "0123456789abcdef");
			print->total_value += ft_len_hexa(print->nbr);
		}
		else
		{
			ft_putnbr_base(print->nbr, "0123456789ABCDEF");
			print->total_value += ft_len_hexa(print->nbr);
		}

	}
	else if (fmt == '%')
	{
		write(1, "%", 1);
		print->total_value++;
	}
	else
	{
		write(1, &fmt, 1);
		print->total_value++;
	}
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
			ft_cest_quoi(&print, fmt[i]);
		}
		else if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			print.total_value++;
		}
		i++;
	}
	return (print.total_value);
	printf("%d", i);
}

#include <stdio.h>
int main()
{
	int a = 50;
	char *nice = "NICE!";
	int *pointer = &a;
	int i;
	int f;

	f = printf("%x de chapeau,\n", 40595);
	i = ft_printouf("%x de chapeau,\n", 40595);
	printf("\nvrai %d, moi %d\n\n", f, i);

	printf("ft_printouf :%d\n", i);
	printf("printf: %d\n\n", f);

	i = ft_printouf("my gnl is kind of an %s %s it is %d cm long and gives a %s ammount of pleasure\n %x\n", "attention", "whore", 22, "tromandous", 429);
	f = printf("my gnl is kind of an %s %s it is %d cm long and gives a %s ammount of pleasure\n %x\n", "attention", "whore", 22, "tromandous", 429);
	printf("\nvrai %d, moi %d", f, i);
return (0);
}
