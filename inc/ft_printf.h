/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:46:14 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/09 19:41:20 by jzeybel          ###   ########.fr       */
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
	char	c;
	int		i;
	int		n;
	int		sign;
	int		minus;
	int		zero;
	int		prec;
	int		width;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_parsing(va_list ap, const char *format, t_flags *flags);
void			ft_parse_flag(va_list ap, const char *format, t_flags *flags);
void			ft_parse_width(va_list ap, const char *format, t_flags *flags);
void			ft_parse_prec(va_list ap, const char *format, t_flags *flags);
void			ft_parse_conv(va_list ap, const char *format, t_flags *flags);
void			init_flags(t_flags *flags, int i);

void			init_buf(void);
void			writec_buf(unsigned char s);
void			writestr_buf(char *s, int i);
int				display_buf(int fd);
void			fill_buffer(char s, int i);

void			width(int len, t_flags *flags);
int				width_next(int len, t_flags *flags);
void			prec(int len, t_flags *flags);
void			write_c(va_list ap, t_flags *flags);
void			write_s(va_list ap, t_flags *flags);
void			write_pct(t_flags *flags);
void			write_di(va_list ap, t_flags *flags);
void			write_u(va_list ap, t_flags *flags);
void			write_x(va_list ap, t_flags *flags);
void			write_upx(va_list ap, t_flags *flags);
void			write_p(va_list ap, t_flags *flags);
#endif
