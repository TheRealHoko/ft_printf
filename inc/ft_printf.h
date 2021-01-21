/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:46:14 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/21 13:18:29 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

# define SIZE 100

typedef struct	s_buf
{
	char	buf[SIZE];
	int		i;
	int		size;
}				t_buf;

int		ft_printf(const char *, ...);
void	ft_parsing(va_list ap, const char *format);
void	ft_parseconv(va_list ap, const char **format);
void	ft_parseflag(const char **format);

void	writec_buf(char s);
void	writestr_buf(char *s);
void    init_buf(void);
int		display_buf(int fd);
void    fill_buffer(char s, int i);

void	write_c(va_list ap);
void	write_s(va_list ap);
void	write_p(va_list ap);
void	write_di(va_list ap);
void	write_u(va_list ap);
void	write_x(va_list ap);
void	write_X(va_list ap);
void	write_pct();
void	write_llldx(va_list ap, const char **format);
#endif
