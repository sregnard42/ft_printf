/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:56:54 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/13 15:42:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_nbrlen(t_printf *p, long double nb, unsigned int base)
{
	size_t		len;

	if (p->flags & FLAG_PRECISION && p->precision == 0 && nb == 0)
		return (0);
	len = 1;
	while (nb >= base && ++len)
		nb /= base;
	(p->precision >= len) ? (p->precision -= len) : (p->precision = 0);
	len += p->precision;
	return (len);
}

int			pf_nbrpad(t_printf *p, long double nb, unsigned int base)
{
	char	*c;
	size_t	len;

	c = pf_prefix(p, nb, base);
	len = ft_strlen(c);
	if (p->flags & FLAG_LEFT_ALIGN)
		c != 0 ? pf_buffer(p, c, len) : 0;
	else if (p->flags & FLAG_0 && !(p->flags & FLAG_PRECISION))
	{
		c != 0 ? pf_buffer(p, c, len) : 0;
		pf_padding(p, pf_nbrlen(p, nb, base));
	}
	else
	{
		pf_padding(p, pf_nbrlen(p, nb, base) + len);
		c != 0 ? pf_buffer(p, c, len) : 0;
	}
	return (0);
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
	if (p->flags & FLAG_LEFT_ALIGN)
		return (pf_padding(p, len));
	return (0);
}

int			pf_nb_signed(t_printf *p)
{
	unsigned long long	nb;
	long long			arg;

	p->flags & FLAG_PRECISION ? (p->flags &= ~FLAG_0) : ++p->precision;
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

int			pf_nb_unsigned(t_printf *p)
{
	unsigned long long	arg;
	unsigned int		base;
	char				c;

	c = *p->format;
	p->flags & FLAG_PRECISION ? (p->flags &= ~FLAG_0) : ++p->precision;
	if (p->flags & FLAG_CHAR)
		arg = (unsigned char)va_arg(p->ap, unsigned int);
	else if (p->flags & FLAG_SHORT && c != 'U')
		arg = (unsigned short)va_arg(p->ap, unsigned int);
	else if (p->flags & FLAG_LONG || c == 'O' || c == 'U')
		arg = va_arg(p->ap, unsigned long);
	else if (p->flags & FLAG_LONG_LONG)
		arg = va_arg(p->ap, unsigned long long);
	else if (c == 'p')
		arg = (unsigned long long)va_arg(p->ap, void *);
	else
		arg = va_arg(p->ap, unsigned int);
	(c == 'o' || c == 'O') ? base = 8 : 0;
	(c == 'u' || c == 'U') ? base = 10 : 0;
	(c == 'x' || c == 'X' || c == 'p') ? base = 16 : 0;
	pf_nbrpad(p, arg, base);
	return (pf_putnbr(p, arg, base));
}
