/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:59:17 by abonard           #+#    #+#             */
/*   Updated: 2022/01/26 19:01:34 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *fmt, ... )
{
	int		i;
	t_print	print;

	i = 0;
	va_start(print.args, fmt);
	ft_initialise_tab(&print);

	while (fmt && fmt[i])
	{
		if ((fmt[i - 1] == '%') && (i > 0))
		{
			ft_parsing(&print, fmt[i]);
		}
		else if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			print.total_value++;
		}
		else
			print.pct = 0;
		i++;
	}
	return (print.total_value);
}
/*#include <limits.h>
#include <stdio.h>
int main()
{
//	int a = 50;
	//char *nice = "NICE!";
//	int *pointer = &a;
	int i;
	int f;

//	f = printf("%x de chapeau, lalala %p\n, %u\n", 40595, pointer, -1000);
//	i = ft_printf("%x de chapeau, lalala %p\n, %u\n", 40595, pointer, -1000);
//	printf("\nvrai %d, moi %d\n\n", f, i);

//	printf("ft_printouf :%d\n", i);
//	printf("printf: %d\n\n", f);

//	i = ft_printf("my gnl is kind of an %s %s it iscm long and gives a %s ammount of pleasure\n", "attention", "whore","tromandous");
//	f = printf("my gnl is kind of an %s %s it iscm long and gives a %s ammount of pleasure\n", "attention", "whore", "tromandous");
	i = ft_printf("moi ->%d\n", 0);
	f = printf("vrai ->%d\n", 0);

//	i = ft_printf(" %x\n");
//	f = printf(" %%%% \n");
	printf("24 -> %x\n ", LONG_MAX);
	printf("25 -> %x\n ", LONG_MIN);
	printf("27 -> %x\n ", ULONG_MAX);
	printf("28 ->  %x\n ", 9223372036854775807LL);
	printf("29 -> %x %x %x %x %x %x %x\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	ft_printf("24 -> %x\n ", LONG_MAX);
	ft_printf("25 -> %x\n ", LONG_MIN);
	ft_printf("27 -> %x\n ", ULONG_MAX);
	ft_printf("28 ->  %x\n ", 9223372036854775807LL);
	ft_printf("29 -> %x %x %x %x %x %x %x\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	ft_printf("\nvrai %d, moi %d", f, i);
return (0);
}*/
