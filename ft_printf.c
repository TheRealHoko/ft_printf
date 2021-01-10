/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:40:20 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/10 04:13:42 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_parsing(va_list ap, const char *format, int size)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			ft_parseconv(ap, &format, size);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
		size++;
	}
	return (size);
}

int	ft_parseconv(va_list ap, const char **format, int size)
{

	(*format)++;
	if (**format == 'c')
		size += ft_putchar_fd(va_arg(ap, int), 1);
	else if (**format == 's')
		size += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (**format == 'p')
	{
		size += ft_printf("0x");
		size += ft_putbase_fd(va_arg(ap, unsigned long), "0123456789abcdef", 16, 1);
	}
	else if (**format == 'd' || **format == 'i')
		/*size +=*/ ft_putnbr_fd(va_arg(ap, int), 1);
	else if (**format == 'u')
		/*size +=*/ ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (**format == 'x')
		size += ft_putbase_fd(va_arg(ap, unsigned int), "0123456789abcdef", 16, 1);
	else if (**format == 'X')
		size += ft_putbase_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 16, 1);
	else if (**format == '%')
		size += ft_putchar_fd('%', 1);
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'i' || **format == 'd')
			/*size +=*/ ft_putnbr_fd(va_arg(ap, long), 1);
		else if (**format == 'l')
		{
			(*format)++;
			if (**format == 'i' || **format == 'd')
				/*size +=*/ ft_putnbr_fd(va_arg(ap, long long), 1);
		}
	}
	return (size);
	(*format)++;
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int size;

	size = 0;
	va_start(ap, format);
	size = ft_parsing(ap, format, size);
	va_end(ap);
	//printf("\n\n\nsize %d\n", size);

	return (size);
}
