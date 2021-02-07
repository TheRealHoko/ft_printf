/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_diupxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:42:27 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/07 17:53:52 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_di(va_list ap, t_flags *flags)
{
	char		*array;
	long long	i;
	int			len;
	int			iss;

	iss = 0;
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
		width(len, flags, iss);
	else if ((flags->prec > len) || (flags->sign == -1))
		prec(len, flags, iss);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags, iss);
}

void	write_u(va_list ap, t_flags *flags)
{
	char			*array;
	int				len;
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (!i)
		flags->n = 0;
	array = ft_lltoa(i);
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags, 0);
	else if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags, 0);
}

void	write_x(va_list ap, t_flags *flags)
{
	char			*array;
	int				len;
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (!i)
		flags->n = 0;
	array = ft_ulltoa_base(i, "0123456789abcdef");
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags, 0);
	else if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags, 0);
}

void	write_X(va_list ap, t_flags *flags)
{
	char			*array;
	int				len;
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (!i)
		flags->n = 0;
	array = ft_ulltoa_base(i, "0123456789ABCDEF");
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags, 0);
	else if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags, 0);
}

void	write_p(va_list ap, t_flags *flags)
{
	char				*array;
	int					len;
	unsigned long long	i;

	i = va_arg(ap, unsigned long long);
	if (!i)
		flags->n = 0;
	array = ft_ulltoa_base(i, "0123456789abcdef");
	len = ft_strlen(array);
	if (!flags->prec && !i)
		len = 0;
	if ((flags->width || flags->zero) && !flags->minus)
		width(len + 2, flags, 2);
	else if (flags->prec > (len + 2))
		prec(len + 2, flags, 2);
	writestr_buf("0x", 2);
	if ((flags->prec != 0) || (i != 0))
		writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len + 2, flags, 2);
}
