/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:36 by abonard           #+#    #+#             */
/*   Updated: 2021/12/10 17:05:28 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
#include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int	wdt;
	int prc;
	int	zero;
	int	pnt;
	int	dash;
	int	total_value;
	int	sign;
	int	is_zero;
	int	perc;
	int	sp;
}	t_print;

#endif
