/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:11:44 by abonard           #+#    #+#             */
/*   Updated: 2022/01/26 19:01:29 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(t_print *print, const char fmt)
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
		ft_string(print);
	else if (fmt == 'p')
	{
		print->nbr = va_arg(print->args, unsigned long long int);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(print->nbr, "0123456789abcdef");
		print->total_value += ft_len_hexa(print->nbr) + 2;
	}
	else if (fmt == 'u')
	{
		print->nbr = va_arg(print->args, unsigned  int);
		ft_putnbr_base(print->nbr, "0123456789");
		print->total_value += ft_len(print->nbr);
	}
	else if (fmt == 'x' || fmt == 'X')
	{
		print->nb = va_arg(print->args,unsigned int);
		if (fmt == 'x')
			ft_putnbr_base(print->nb, "0123456789abcdef");
		else
			ft_putnbr_base(print->nb, "0123456789ABCDEF");
		print->total_value += ft_len_hexa(print->nb);
	}
	else if (fmt == '%' && print->pct == 0)
	{
		write(1, "%", 1);
		print->total_value++;
		print->pct = 1;
	}
	else
	{
		if (print->pct == 1 && fmt == '%')
			print->pct = 0;
		else
		{
			write(1, &fmt, 1);
			print->total_value++;
		}
	}
	return (0);
}
