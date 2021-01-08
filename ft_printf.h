/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:46:14 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/08 17:34:54 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int ft_printf(const char *, ...);
int ft_parsing(va_list ap, const char *format, int size);
int ft_parseconv(va_list ap, const char **format);

#endif
