/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cspct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:18 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/07 20:30:59 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(int len, t_flags *flags, int iss)
{
	int	i;

	if (!flags->prec && !flags->n)
		i = flags->width;
	else if ((flags->prec > len) && (!iss || (iss == 2)))
		i = flags->width - flags->prec - iss;
	else
		i = flags->width - len;
	if (flags->zero && (flags->prec == -1))
	{
		if (flags->sign == -1)
			writec_buf('-');
		fill_buffer('0', i);
	}
	else
	{
		fill_buffer(' ', i);
		if ((flags->sign == -1) && !flags->minus)
		{
			writec_buf('-');
			flags->sign = 1;
		}
	}
	if ((flags->prec > len) && !flags->minus)
		return (prec(len, flags, iss));
}

void	prec(int len, t_flags *flags, int iss)
{
	int	i;

	if (flags->sign == -1)
		writec_buf('-');
	if (!iss && (flags->prec > len))
	{
		i = flags->prec - len;
		fill_buffer('0', i);
	}
}

void	write_c(va_list ap, t_flags *flags)
{
	unsigned char	c;

	c = va_arg(ap, int);
	if (flags->width && !flags->minus)
		width(1, flags, 0);
	writec_buf(c);
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
		if (flags->prec < len)
			len = flags->prec;
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
