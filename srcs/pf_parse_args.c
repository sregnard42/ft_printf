/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:48:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/05 18:11:04 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(t_printf *p)
{
	if (*p->format == 'c')
		return (pf_putchar(va_arg(p->ap, unsigned int)));
	if (*p->format == 's')
		return (pf_putstr(va_arg(p->ap, char *)));
	if (*p->format == 'p')
		return (pf_putaddr(va_arg(p->ap, unsigned int)));
	if (*p->format == 'd')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 10, 0));
	if (*p->format == 'i')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 10, 0));
	if (*p->format == 'o')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 8, 0));
	if (*p->format == 'u')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 10, 0));
	if (*p->format == 'x')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 16, 0));
	if (*p->format == 'X')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 16, 1));
	if (*p->format == 'f')
		return (pf_putnbr_u(va_arg(p->ap, unsigned int), 10, 0));
	if (*p->format == '%')
		return (pf_putchar(*(p->format)));
	return (0);
}

static int	flags(t_printf *p)
{
	if (*p->format == 'h')
	{
		if (*++p->format == 'h')
		{
			++p->format;
			return (p->flags |= FLAG_CHAR);
		}
		return (p->flags |= FLAG_SHORT);
	}
	if (*p->format == 'l')
	{
		if (*++p->format == 'l')
		{
			++p->format;
			return (p->flags |= FLAG_LONG_LONG);
		}
		return (p->flags |= FLAG_LONG);
	}
	if (*p->format == 'L')
	{
		++p->format;
		return (p->flags |= FLAG_LONG_DOUBLE);
	}
	return (0);
}


static int	width_precision(t_printf *p)
{
	if (*p->format >= '1' && *p->format <= '9')
	{
		p->width = pf_atoi(p->format++);
		p->flags |= FLAG_WIDTH;
		while (*p->format >= '0' && *p->format <= '9')
			++(p->format);
	}
	if (*p->format == '.')
	{
		p->precision = pf_atoi(++p->format);
		p->flags |= FLAG_PRECISION;
		while (*p->format >= '0' && *p->format <= '9')
			++(p->format);
	}
	return (1);
}

static int	options(t_printf *p)
{
	if (*p->format == '#')
		return (p->flags |= FLAG_HASH);
	if (*p->format == '+')
		return (p->flags |= FLAG_PLUS);
	if (*p->format == ' ')
		return (p->flags |= FLAG_SPACE);
	if (*p->format == '-') 
		return (p->flags |= FLAG_LEFT_ALIGN);
	if (*p->format == '0')
		return (p->flags |= FLAG_RIGHT_ALIGN);
	return (0);
}

int		pf_parse_args(t_printf *p)
{
	unsigned int	written;

	written = 0;
	p->flags = 0;
	p->width = 0;
	p->precision = 1;
	++(p->format);
	if (*p->format == '%')
		return (pf_putchar('%'));
	while (options(p))
		++(p->format);
	width_precision(p);
	flags(p);
	written = (conversion(p));
	if (p->flags & FLAG_LEFT_ALIGN)
		while (written < p->width)
			written += write(1, " ", 1);
	return (written);
}
