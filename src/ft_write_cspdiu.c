/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cspdiu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:18 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/29 15:54:10 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_c(va_list ap, t_flags *flags)
{
	(void)flags;
	writec_buf(va_arg(ap, int));
}

void	write_s(va_list ap, t_flags *flags)
{
	(void)flags;
	writestr_buf(va_arg(ap, char *));
}

void	write_p(va_list ap, t_flags *flags)
{
	(void)flags;
	writestr_buf("0x");
	writestr_buf(ft_ulltoa_base(va_arg(ap, unsigned long long), \
				"0123456789abcdef"));
}
void	write_di(va_list ap, t_flags *flags)
{
	char	*array;

	array = ft_lltoa(va_arg(ap, int));
	if (flags->zero)
		fill_buffer('0', flags->width - ft_strlen(array));
	writestr_buf(array);
}

void	write_u(va_list ap, t_flags *flags)
{
	char	*array;

	array = ft_lltoa(va_arg(ap, unsigned int));
	if (flags->zero)
		fill_buffer('0', flags->width - ft_strlen(array));
	writestr_buf(array);
}
