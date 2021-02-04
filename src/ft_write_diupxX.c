/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_diupxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:42:27 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/04 17:22:13 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_di(va_list ap, t_flags *flags)
{
	char		*array;
	long long	i;
	int			len;

	i = va_arg(ap, int);
	if (i < 0)
	{
		flags->sign = -1;
		flags->width--;
	}
	array = ft_lltoa(i * flags->sign);
	len = ft_strlen(array);
	if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
	flags->sign = 1;
}

void	write_u(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;

	array = ft_lltoa(va_arg(ap, unsigned int));
	len = ft_strlen(array);
	if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_x(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;

	array = ft_ulltoa_base(va_arg(ap, int), "0123456789abcdef");
	len = ft_strlen(array);
	if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_X(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;


	array = ft_ulltoa_base(va_arg(ap, int), "0123456789ABCDEF");
	len = ft_strlen(array);
	if (flags->prec > len)
		prec(len, flags, 0);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len, flags);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}

void	write_p(va_list ap, t_flags *flags)
{
	char	*array;
	int		len;

	array = ft_ulltoa_base(va_arg(ap, unsigned long long), "0123456789abcdef");
	len = ft_strlen(array);
	if ((flags->width || flags->zero) && !flags->minus)
		width(len + 2, flags);
	writestr_buf("0x", 2);
	writestr_buf(array, len);
	if (flags->width && flags->minus)
		width(len, flags);
}
