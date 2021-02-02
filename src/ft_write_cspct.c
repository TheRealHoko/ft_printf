/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cspct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:18 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/02 13:39:05 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(int len, t_flags *flags)
{
	flags->width -= len;
	if (flags->sign == -1)
		writec_buf('-');
	if (flags->zero)
		fill_buffer('0', flags->width);
	else
		fill_buffer(' ', flags->width);
}

void	prec(int len, t_flags *flags)
{
	flags->prec -= len;
	if (flags->sign == -1)
		writec_buf('-');
	fill_buffer('0', flags->prec);
}

void	write_c(va_list ap, t_flags *flags)
{
	char	array[2];

	array[0] = va_arg(ap, int);
	if (flags->width && !flags->minus)
		width(1, flags);
	writestr_buf(array, 1);
	if (flags->width && flags->minus)
		width(1, flags);
}

void	write_s(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;

	array = va_arg(ap, char *);
	len = ft_strlen(array);
	if (flags->prec > -1)
		len = flags->prec;
	if (flags->width && !flags->minus)
		width(len, flags);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_pct(t_flags *flags)
{
	(void)flags;
	char	array[2];

	array[0] = '%';
	writestr_buf(array, 1);
}


