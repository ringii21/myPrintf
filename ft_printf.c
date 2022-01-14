/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:06:09 by abonard           #+#    #+#             */
/*   Updated: 2022/01/14 16:36:44 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "libft.h"
t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->total_value = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}


int	ft_check(char c, char *str)
{
	int	i;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_fmt_eval(char *tab, char *fmt, int i)
{
	char *set;

	set = "dcsupxX%";
	while (ft_check(fmt[i], set) == 0)
	{
		if (fmt[i] == '.')
		{
			tab->pnt = 1;
			i++;
		}
		if (fmt[i] == '-') 
		{
			tab->dash = 1;
			i++;
		}
		if (fmt[i] == '0')
		{
			tab->is_zero = 1;
			i++;
		}
	}
}
int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (tab == NULL)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, fmt);
	i = -1;
	ret= 0;
	while (fmt[++i])
	{
		if(fmt[i] == '%')
			i = ft_fmt_eval(tab, fmt, i + 1);
		else
			ret = ret + write(1, &fmt[i], 1);
	}
	va_end(tab->args);
	ret = ret + tab->total_value;
	free (tab);
	return (ret);
}
