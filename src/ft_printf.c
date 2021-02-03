/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:40:20 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/03 21:48:53 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
void	init_flags(t_flags *flags)
{
	flags->i = 0;
	flags->sign = 1;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
}

void	ft_parsing(va_list ap, const char *format, t_flags *flags)
{
	while (format[flags->i])
	{
		if ((format[flags->i] == '%') && format[flags->i + 1])
			ft_parse_flag(ap, format, flags);
		else
			writec_buf(format[flags->i]);
		if (format[flags->i] == '\0')
			break;
		flags->i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags flags;

	init_buf();
	init_flags(&flags);
	va_start(ap, format);
	ft_parsing(ap, format, &flags);
	va_end(ap);

	return (display_buf(1));
}
