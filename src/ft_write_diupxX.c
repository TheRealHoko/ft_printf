/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_diupxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:42:27 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/09 16:00:19 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

void	write_di(va_list ap, t_flags *flags)
{
	char		*array;
	long long	i;
	int			len;

	flags->c = 'd';
	i = va_arg(ap, int);
	if (!i)
		flags->n = 0;
	if (i < 0)
	{
		flags->sign = -1;
		if (flags->width)
			flags->width--;
	}
	array = ft_lltoa(i * flags->sign);
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	else if ((flags->prec > len) || (flags->sign == -1))
		prec(len, flags);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_u(va_list ap, t_flags *flags)
{
	char			*array;
	int				len;
	unsigned int	i;

	flags->c = 'u';
	i = va_arg(ap, unsigned int);
	if (!i)
		flags->n = 0;
	array = ft_lltoa(i);
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	else if (flags->prec > len)
		prec(len, flags);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_x(va_list ap, t_flags *flags)
{
	char			*array;
	int				len;
	unsigned int	i;

	flags->c = 'x';
	i = va_arg(ap, unsigned int);
	if (!i)
		flags->n = 0;
	array = ft_ulltoa_base(i, "0123456789abcdef");
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	else if (flags->prec > len)
		prec(len, flags);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_X(va_list ap, t_flags *flags)
{
	char			*array;
	int				len;
	unsigned int	i;

	flags->c = 'X';
	i = va_arg(ap, unsigned int);
	if (!i)
		flags->n = 0;
	array = ft_ulltoa_base(i, "0123456789ABCDEF");
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	else if (flags->prec > len)
		prec(len, flags);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_p(va_list ap, t_flags *flags)
{
	char				*array;
	int					len;
	unsigned long long	i;

	flags->c = 'p';
	i = va_arg(ap, unsigned long long);
	if (!i)
		flags->n = 0;
	array = ft_ulltoa_base(i, "0123456789abcdef");
	len = ft_strlen(array) + 2;
	if (!flags->prec && !i)
		len = 0;
	if ((flags->width || flags->zero) && !flags->minus)
	{
		if (flags->zero)
			writestr_buf("0x", 2);
		width(len, flags);
	}
	if ((flags->prec > len) && !flags->minus)
		prec(len, flags);
	if (!flags->zero)
		writestr_buf("0x", 2);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len - 2);
	if (flags->width && flags->minus)
		width(len, flags);
	if ((flags->prec > len) && flags->minus)
		prec(len, flags);
}
