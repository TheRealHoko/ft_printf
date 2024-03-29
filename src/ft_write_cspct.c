/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cspct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:18 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/09 19:40:48 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(int len, t_flags *flags)
{
	int	i;

	i = width_next(len, flags);
	if (flags->zero && (flags->c || (flags->prec == -1)))
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
		return (prec(len, flags));
}

void	prec(int len, t_flags *flags)
{
	int	i;

	if (!ft_ischarset(flags->c, "cs%"))
		flags->c = 0;
	if (flags->sign == -1)
		writec_buf('-');
	if (!flags->c && (flags->prec > len))
	{
		i = flags->prec - len;
		fill_buffer('0', i);
	}
}

void	write_c(va_list ap, t_flags *flags)
{
	unsigned char	c[2];

	flags->c = 'c';
	c[0] = va_arg(ap, int);
	if (flags->width && !flags->minus)
		width(1, flags);
	writec_buf(*c);
	if (flags->width && flags->minus)
		width(1, flags);
}

void	write_s(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;

	flags->c = 's';
	array = va_arg(ap, char *);
	if (!array)
		array = "(null)";
	len = ft_strlen(array);
	if (flags->prec > -1)
		if (flags->prec < len)
			len = flags->prec;
	if (flags->width && !flags->minus)
		width(len, flags);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_pct(t_flags *flags)
{
	char	array[2];

	flags->c = '%';
	array[0] = '%';
	if (flags->width && !flags->minus)
		width(1, flags);
	writestr_buf(array, 1);
	if (flags->width && flags->minus)
		width(1, flags);
}
