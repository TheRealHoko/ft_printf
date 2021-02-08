/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:55:56 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/07 21:02:12 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_parse_flag(va_list ap, const char *format, t_flags *flags)
{
	flags->i++;
	if (format[flags->i] == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	else if (format[flags->i] == '0')
	{
		if (!flags->minus)
			flags->zero = 1;
	}
	else
		return (ft_parse_width(ap, format, flags));
	return (ft_parse_flag(ap, format, flags));
}

void	ft_parse_width(va_list ap, const char *format, t_flags *flags)
{
	if (format[flags->i] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
		flags->i++;
	}
	else if (ft_isrange('1', '9', format[flags->i]))
	{
		flags->width = ft_atoll(format + flags->i);
		while (ft_isdigit(format[flags->i]))
			flags->i++;
	}
	else
		return (ft_parse_prec(ap, format, flags));
	return (ft_parse_width(ap, format, flags));
}

void	ft_parse_prec(va_list ap, const char *format, t_flags *flags)
{
	if (format[flags->i] == '.')
	{
		flags->prec = 0;
		flags->i++;
	}
	else if (format[flags->i] == '*')
	{
		flags->prec = va_arg(ap, int);
		if (flags->prec < 0)
			flags->prec = -1;
		flags->i++;
	}
	else if (ft_isdigit(format[flags->i]))
	{
		flags->prec = ft_atoll(format + flags->i);
		while (ft_isdigit(format[flags->i]))
			flags->i++;
	}
	else
		return (ft_parse_conv(ap, format, flags));
	return (ft_parse_prec(ap, format, flags));
}

void	ft_parse_conv(va_list ap, const char *format, t_flags *flags)
{
	if (format[flags->i] == 'c')
		write_c(ap, flags);
	else if (format[flags->i] == 's')
		write_s(ap, flags);
	else if (format[flags->i] == 'p')
		write_p(ap, flags);
	else if (format[flags->i] == 'd' || format[flags->i] == 'i')
		write_di(ap, flags);
	else if (format[flags->i] == 'u')
		write_u(ap, flags);
	else if (format[flags->i] == 'x')
		write_x(ap, flags);
	else if (format[flags->i] == 'X')
		write_X(ap, flags);
	else if (format[flags->i] == '%')
		write_pct(flags);
	init_flags(flags, 0);
}
