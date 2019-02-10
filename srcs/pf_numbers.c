/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:56:54 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/10 19:58:25 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_nbrlen(t_printf *p, unsigned long long nb, unsigned int base)
{
	size_t		len;

	if (p->flags & FLAG_PRECISION && p->precision == 0 && nb == 0)
		return (0);
	len = 1;
	while (nb >= base && ++len)
		nb /= base;
	(p->precision >= len) ? (p->precision -= len) : (p->precision = 0);
	len += p->precision;
	if (!(p->flags & FLAG_LEFT_ALIGN) && !(p->flags & FLAG_0))
		if (((p->flags & FLAG_PLUS || p->flags & FLAG_SPACE) 
					&& p->flags & FLAG_POSITIVE)
				|| p->flags & FLAG_NEGATIVE)
			len += 1;
	if (!(p->flags & FLAG_0) && p->flags & FLAG_HASH && nb != 0)
	{
		base == 8 ? len += 1 : 0;
		base == 16 ? len += 2 : 0;
	}
	return (len);
}

static int	pf_putnbr(t_printf *p, unsigned long long nb, unsigned int base)
{
	size_t	len;
	char	c;

	if (p->flags & FLAG_PRECISION && p->precision == 0 && nb == 0)
		return (0);
	if (p->flags & FLAG_LEFT_ALIGN)
		len = pf_nbrlen(p, nb, base);
	while (p->precision-- > 0)
		pf_buffer(p, "0", 1);
	p->precision = 0;
	if (nb >= base)
		pf_putnbr(p, nb / base, base);
	nb %= base;
	if (nb < 10)
		c = nb + '0';
	else if (*p->format == 'X')
		c = nb - 10 + 'A';
	else
		c = nb - 10 + 'a';
	pf_buffer(p, &c, 1);
	nb /= base;
	if (p->flags & FLAG_LEFT_ALIGN)
		return (pf_padding(p, len));
	return (0);
}

static int	pf_nbrpad(t_printf *p, unsigned long long nb, unsigned int base)
{
	char *c;

	c = 0;
	(p->flags & FLAG_NEGATIVE) ?  c = "-" : 0;
	(p->flags & FLAG_POSITIVE && p->flags & FLAG_PLUS) ? c = "+" : 0;
	(p->flags & FLAG_POSITIVE && p->flags & FLAG_SPACE) ? c = " " : 0;
	if (p->flags & FLAG_HASH)
		(base == 8) ? c = "0": 0;
	if (p->flags & FLAG_HASH && nb != 0)
	{
		(base == 16 && *p->format == 'x') ? c = "0x": 0;
		(base == 16 && *p->format == 'X') ? c = "0X": 0;
	}
	if (p->flags & FLAG_LEFT_ALIGN)
		c != 0 ? pf_buffer(p, c, ft_strlen(c)) : 0;
	else if (p->flags & FLAG_0 && !(p->flags & FLAG_PRECISION))
	{
		c != 0 ? pf_buffer(p, c, ft_strlen(c)) : 0;
		pf_padding(p, pf_nbrlen(p, nb, base));
	}
	else
	{
		pf_padding(p, pf_nbrlen(p, nb, base));
		c != 0 ? pf_buffer(p, c, ft_strlen(c)) : 0;
	}
	return (0);
}

int		pf_nb_signed(t_printf *p)
{
	unsigned long long	nb;
	long long		arg;

	if (p->flags & FLAG_CHAR)
		arg = (char)va_arg(p->ap, int);
	else if (p->flags & FLAG_SHORT)
		arg = (short)va_arg(p->ap, int);
	else if (p->flags & FLAG_LONG)
		arg = va_arg(p->ap, long);
	else if (p->flags & FLAG_LONG_LONG)
		arg = va_arg(p->ap, long);
	else
		arg = va_arg(p->ap, int);
	nb = arg >= 0 ? arg : -arg;	
	p->flags |= arg >= 0 ? FLAG_POSITIVE : FLAG_NEGATIVE;
	pf_nbrpad(p, nb, 10);
	return (pf_putnbr(p, nb, 10));
}

int		pf_nb_unsigned(t_printf *p)
{
	unsigned long long	arg;
	unsigned int		base;
	char			c;

	c = *p->format;
	if (p->flags & FLAG_CHAR)
		arg = (unsigned char)va_arg(p->ap, unsigned int);
	else if (p->flags & FLAG_SHORT)
		arg = (unsigned short)va_arg(p->ap, unsigned int);
	else if (p->flags & FLAG_LONG)
		arg = va_arg(p->ap, unsigned long);
	else if (p->flags & FLAG_LONG_LONG)
		arg = va_arg(p->ap, unsigned long long);
	else if (c == 'p')
		arg = (unsigned long long)va_arg(p->ap, void *);
	else
		arg = va_arg(p->ap, unsigned int);
	(c == 'o') ? base = 8 : 0;
	(c == 'u' || c == 'U') ? base = 10 : 0;
	(c == 'x' || c == 'X' || c == 'p') ? base = 16 : 0;
	pf_nbrpad(p, arg, base);
	return (pf_putnbr(p, arg, base));
}
