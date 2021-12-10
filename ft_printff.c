/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:59:17 by abonard           #+#    #+#             */
/*   Updated: 2021/12/10 20:11:10 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
#define GROSSE 10000
typedef	struct s_print
{
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
	char *pute = NULL;

	pute = va_arg(print->args, char *);
	ft_putstr_fd(pute, 1);
	return (1);
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

		//void * a caster en char *
	}
	else if (fmt == 'u')
	{
		//unsigned int
	}
	else if (fmt == 'x' || fmt == 'X')
	{
		//exadecimal
	}
	else if (fmt == '%')
	{
		write(1, "%", 1);
	}
	return (-1);
}

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
		}
		i++;

	}
	return (print.total_value);
}

int main()
{
	char *nice = "NICE!";
	ft_printouf("je m'appel %s mon penis fait %d, c'est %s %%", "BORAT", 17, "NICE");
}
