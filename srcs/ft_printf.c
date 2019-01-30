/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:23:36 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/30 16:15:12 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	conversion(const char *format, va_list ap)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*format == 's')
	   return (ft_putstr(va_arg(ap, char *)));
	if (*format == 'p')
	   return (ft_putaddr(va_arg(ap, void *)));
	return (-1);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int 	i;

	va_start(ap, format);
	i = 0;
	while (format && *format)
	{
		while (format && *format != '%')
			ft_putchar(*format++);
		conversion(++format, ap);
	}
	va_end(ap);
	return (0);
}
