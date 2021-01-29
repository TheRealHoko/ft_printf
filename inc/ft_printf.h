/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:46:14 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/28 15:42:31 by jzeybel          ###   ########.fr       */
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

typedef struct	s_flags
{
	int	i;
	int	minus;
	int	zero;
	int	precision;
	int	width;
}				t_flags;

int		ft_printf(const char *, ...);
void	ft_parsing(va_list ap, const char *format, t_flags *flags);
void	ft_parse_flag(va_list ap, const char *format, t_flags *flags);
void	ft_parse_width(va_list ap, const char *format, t_flags *flags);
void	ft_parse_conv(va_list ap, const char *format, t_flags *flags);
void    init_flags(t_flags *flags);

void    init_buf(void);
void	writec_buf(char s);
void	writestr_buf(char *s);
int		display_buf(int fd);
void    fill_buffer(char s, int i);

void	write_c(va_list ap, t_flags *flags);
void	write_s(va_list ap, t_flags *flags);
void	write_p(va_list ap, t_flags *flags);
void	write_di(va_list ap, t_flags *flags);
void	write_u(va_list ap, t_flags *flags);
void	write_x(va_list ap, t_flags *flags);
void	write_X(va_list ap, t_flags *flags);
void	write_pct(t_flags *flags);
void	write_llldx(va_list ap, const char *format, t_flags *flags);
#endif
