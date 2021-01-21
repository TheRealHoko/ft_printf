/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_xXpctl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:42:27 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/21 12:57:44 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	write_x(va_list ap)
{
	writestr_buf(ft_ulltoa_base(va_arg(ap, int), "0123456789abcdef"));
}

void	write_X(va_list ap)
{
	writestr_buf(ft_ulltoa_base(va_arg(ap, int), "0123456789ABCDEF"));
}

void	write_pct()
{
	writec_buf('%');
}

void	write_llldx(va_list ap, const char **format)
{
	(*format)++;                                                            
	if (**format == 'i' || **format == 'd')                                 
		writestr_buf(ft_lltoa(va_arg(ap, long)));                           
	else if (**format == 'x')                                               
		writestr_buf(ft_ulltoa_base(va_arg(ap, long), "0123456789abcdef")); 
	else if (**format == 'X')                                               
		writestr_buf(ft_ulltoa_base(va_arg(ap, long), "0123456789ABCDEF")); 
	else if (**format == 'l')                                               
	{                                                                       
		(*format)++;                                                        
		if (**format == 'i' || **format == 'd')                             
			writestr_buf(ft_lltoa(va_arg(ap, long long)));                  
		else if (**format == 'x')                                           
			writestr_buf(ft_ulltoa_base(va_arg(ap, long long), "0123456789abcdef"));
		else if (**format == 'X')                                           
			writestr_buf(ft_ulltoa_base(va_arg(ap, long long), "0123456789ABCDEF"));
	}
}
