/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:23:36 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/01 15:38:49 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	flag(const char *format, va_list ap)
{
	if (*format == 'l' && *(format + 1) == 'x')
		return (ft_putaddr(va_arg(ap, unsigned int)));
	return (-1);
}

static int	conversion(const char *format, va_list ap)
{
	if (*format == '%')
		return (ft_putchar(*format));
	if (*format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*format == 'p')
		return (ft_putaddr(va_arg(ap, unsigned int)));
	if (*format == 'o')
		return (ft_putnbr_u(va_arg(ap, unsigned int), 8));
	if (*format == 'x')
		return (ft_putnbr_u(va_arg(ap, unsigned int), 16));
	if (*format == '#')
		return (flag(++format, ap));
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
		while (format && *format && *format != '%')
			ft_putchar(*format++);
		if (*format == '%')
		{
			conversion(++format, ap);
			++format;
		}
	}
	va_end(ap);
	return (0);
}
