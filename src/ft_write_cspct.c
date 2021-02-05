/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cspct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:18 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/05 15:56:52 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(int len, t_flags *flags, int iss)
{
	flags->width -= len;
	if (flags->prec > len)
		flags->width -= flags->prec -len;
	if (flags->zero)
	{
		if (flags->sign == -1)
			writec_buf('-');
		fill_buffer('0', flags->width);
	}
	else
		fill_buffer(' ', flags->width);
	if (flags->prec > len)
		return (prec(len, flags, iss));
}

void	prec(int len, t_flags *flags, int iss)
{
	if (flags->sign == -1)
		writec_buf('-');
	if (!iss)
	{
		flags->prec -= len;
		fill_buffer('0', flags->prec);
	}
}

void	write_c(va_list ap, t_flags *flags)
{
	char	array[2];

	array[0] = va_arg(ap, int);
	if (flags->width && !flags->minus)
		width(1, flags, 0);
	writestr_buf(array, 1);
	if (flags->width && flags->minus)
		width(1, flags, 0);
}

void	write_s(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;

	array = va_arg(ap, char *);
	if (!array)
		array = "(null)";
	len = ft_strlen(array);
	if (flags->prec > -1)
	{
		prec(len, flags, 1);
		if (flags->prec < len)
			len = flags->prec;
	}
	if (flags->width && !flags->minus)
		width(len, flags, 1);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags, 1);
}

void	write_pct(t_flags *flags)
{
	char	array[2];

	array[0] = '%';
	if (flags->width && !flags->minus)
		width(1, flags, 0);
	writestr_buf(array, 1);
	if (flags->width && flags->minus)
		width(1, flags, 0);
}


