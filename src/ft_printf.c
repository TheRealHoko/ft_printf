/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:40:20 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/21 13:58:55 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

void	ft_parsing(va_list ap, const char *format)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			ft_parseflag(&format);
			ft_parseconv(ap, &format);
		}
		else
			writec_buf(*format);
		format++;
	}
}

void	ft_parseflag(const char **format)
{
	if (**format == '-')
	if (**format == '-')
}

void	ft_parseconv(va_list ap, const char **format)
{
	(*format)++;
	if (**format == 'c')
		write_c(ap);
	else if (**format == 's')
		write_s(ap);
	else if (**format == 'p')
		write_p(ap);
	else if (**format == 'd' || **format == 'i')
		write_di(ap);
	else if (**format == 'u')
		write_u(ap);
	else if (**format == 'x')
		write_x(ap);
	else if (**format == 'X')
		write_X(ap);
	else if (**format == '%')
		write_pct();
	else if (**format == 'l')
		write_llldx(ap, format);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	init_buf();
	va_start(ap, format);
	ft_parsing(ap, format);
	va_end(ap);

	return (display_buf(1));
}
