/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:19:32 by jzeybel           #+#    #+#             */
/*   Updated: 2021/02/01 22:15:30 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	t_buf g_buf;

void	init_buf()
{
	g_buf.i = 0;
	g_buf.size = 0;
}

int	display_buf(int fd)
{
	write(fd, g_buf.buf, g_buf.i);
	g_buf.size += g_buf.i;
	g_buf.i = 0;
	return (g_buf.size);
}

void	writec_buf(char s)
{
	g_buf.buf[g_buf.i] = s;
	g_buf.i++;
	if (g_buf.i == SIZE)
		display_buf(1);
}

void	writestr_buf(char *s, int i)
{
	int	j;

	j = -1;
	while (*s && (++j < i))
		writec_buf(*s++);
}

void	fill_buffer(char s, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		writec_buf(s);
}
