/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:40:20 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/08 17:38:37 by jzeybel          ###   ########.fr       */
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
			ft_parseconv(ap, &format);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
		size++;
	}
	return (size);
}

int	ft_parseconv(va_list ap, const char **format)
{

	(*format)++;
	if (**format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	if (**format == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	if (**format == 'd' || **format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	if (**format == 'u')
		ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	if (**format == '%')
		ft_putchar_fd('%', 1);
	if (**format == 'l')
	{
		(*format)++;
		if (**format == 'i' || **format == 'd')
			ft_putnbr_fd(va_arg(ap, long), 1);
	}
	if (**format == 'l' && **(format + 1) == 'l')
		ft_putnbr_fd(va_arg(ap, long long), 1);
	return (0);
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
	printf("\n\n\nsize %d\n", size);

	return (size);
}
