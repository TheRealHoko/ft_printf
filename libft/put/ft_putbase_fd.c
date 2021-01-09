/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:43:21 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/09 21:20:04 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putbase_fd(int n, char *base, size_t size)
{
	if (n / (int)size > 0)
		ft_putbase_fd(n / (int)size, base, (int)size);
	ft_putchar_fd(base[n % (int)size], 1);
}
