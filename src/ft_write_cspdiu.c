/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:18 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/20 17:08:45 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_c(va_list ap)
{
	writec_buf(va_arg(ap, int));
}

void	write_s(va_list ap)
{
	writestr_buf(va_arg(ap, char *));
}

void	write_p(va_list ap)
{
	writestr_buf("0x");
	writestr_buf(ft_ulltoa_base(va_arg(ap, unsigned long long), "0123456789abcdef"));
}
void	write_di(va_list ap)
{
	writestr_buf(ft_lltoa(va_arg(ap, int)));
}

void	write_u(va_list ap)
{
	writestr_buf(ft_lltoa(va_arg(ap, unsigned int)));
}
