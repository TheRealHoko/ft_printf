/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_xXpctl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:42:27 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/29 15:55:36 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_x(va_list ap, t_flags *flags)
{
	char	*array;

	array = ft_ulltoa_base(va_arg(ap, int), "0123456789abcdef");
	if (flags->zero)
		fill_buffer('0', flags->width - ft_strlen(array));
	writestr_buf(array);
}

void	write_X(va_list ap, t_flags *flags)
{
	char	*array;

	array = ft_ulltoa_base(va_arg(ap, int), "0123456789ABCDEF");
	if (flags->zero)
		fill_buffer('0', flags->width - ft_strlen(array));
	writestr_buf(array);
}

void	write_pct(t_flags *flags)
{
	(void)flags;
	writec_buf('%');
}

void	write_llldx(va_list ap, const char *format, t_flags *flags)
{
	(void)flags;
	format++;
	if (*format == 'i' || *format == 'd')
		writestr_buf(ft_lltoa(va_arg(ap, long)));
	else if (*format == 'x')
		writestr_buf(ft_ulltoa_base(va_arg(ap, long), "0123456789abcdef"));
	else if (*format == 'X')
		writestr_buf(ft_ulltoa_base(va_arg(ap, long), "0123456789ABCDEF"));
	else if (*format == 'l')
	{
		format++;
		if (*format == 'i' || *format == 'd')
			writestr_buf(ft_lltoa(va_arg(ap, long long)));
		else if (*format == 'x')
			writestr_buf(ft_ulltoa_base(va_arg(ap, long long), "0123456789abcdef"));
		else if (*format == 'X')
			writestr_buf(ft_ulltoa_base(va_arg(ap, long long), "0123456789ABCDEF"));
	}
}
