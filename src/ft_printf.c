/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:40:20 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/18 03:23:38 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

int	ft_parsing(va_list ap, const char *format)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			ft_parseconv(ap, &format);
		else
			writec_buf(*format);
		format++;
	}
	return (0);
}

int	ft_parseconv(va_list ap, const char **format)
{

	(*format)++;
	if (**format == 'c')
		writec_buf(va_arg(ap, int));
	else if (**format == 's')
		writestr_buf(va_arg(ap, char *));
	else if (**format == 'p')
	{
		writestr_buf("0x");
		writestr_buf(ft_ulltoa_base(va_arg(ap, unsigned long long), "0123456789abcdef"));
	}
	else if (**format == 'd' || **format == 'i')
		writestr_buf(ft_lltoa(va_arg(ap, int)));
	else if (**format == 'u')
		writestr_buf(ft_lltoa(va_arg(ap, unsigned int)));
	else if (**format == 'x')
	  writestr_buf(ft_ulltoa_base(va_arg(ap, int), "0123456789abcdef"));
	else if (**format == 'X')
	  writestr_buf(ft_ulltoa_base(va_arg(ap, int), "0123456789ABCDEF"));
	else if (**format == '%')
		writec_buf('%');
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'i' || **format == 'd')
			writestr_buf(ft_lltoa(va_arg(ap, long)));
		else if (**format == 'x')
			writestr_buf(ft_ulltoa_base(va_arg(ap, long), "0123456789abcdef"));
		else if (**format == 'X')
			writestr_buf(ft_ulltoa_base(va_arg(ap, long), "0123456789ABCDEF"));
		else if (**format == 'l')
		{
			(*format)++;
			if (**format == 'i' || **format == 'd')
				writestr_buf(ft_lltoa(va_arg(ap, long long)));
			else if (**format == 'x')
				writestr_buf(ft_ulltoa_base(va_arg(ap, long long), "0123456789abcdef"));
			else if (**format == 'X')
				writestr_buf(ft_ulltoa_base(va_arg(ap, long long), "0123456789ABCDEF"));
		}
	}
	return (0);
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
