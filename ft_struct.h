/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:36 by abonard           #+#    #+#             */
/*   Updated: 2022/01/26 18:25:17 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef	struct s_print
{
	long long int		nbr;
	unsigned long int	nb;
	va_list				args;
	int					pct;
	int					wdt;
	int					prc;
	int					zero;
	int					dash;
	int					total_value;
	int					sign;
	int					sp;
} t_print;

#endif
