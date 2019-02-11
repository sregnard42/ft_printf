/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:51:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/11 15:19:00 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_nbrlen(t_printf *p, long long unsigned nb)
{
	int		len;

	len = 1;
	while (nb >= 10 && ++len)
		nb /= 10;
	!(p->flags & FLAG_PRECISION) ? p->precision = 6 : 0;
	len += (p->precision == 0) ? 0 : p->precision + 1;
	if (!(p->flags & FLAG_LEFT_ALIGN) && !(p->flags & FLAG_0))
		if (((p->flags & FLAG_PLUS || p->flags & FLAG_SPACE) 
					&& p->flags & FLAG_POSITIVE)
				|| p->flags & FLAG_NEGATIVE)
			len += 1;
	return (len);
}

static int	pf_precision(t_printf *p, long double nb)
{
	size_t	i;

	if (p->precision == 0)
		return (0);
	nb -= (long long)nb;
	i = 0;
	while (i++ < p->precision)
		nb *= 10;
	pf_buffer(p, ".", 1);
	i = pf_itoa(p, (long long unsigned)nb);
	while (i++ < p->precision)
		pf_buffer(p, "0", 1);
	return (0);
}

static int	pf_ftoa(t_printf *p, long double nb)
{
	long long unsigned nbr;
	size_t	len;

	(nb >= 0) ? (nbr = nb) : (nbr = -nb);
	if (p->flags & FLAG_LEFT_ALIGN)
		len = pf_nbrlen(p, nbr);
	pf_itoa(p, nbr);
	pf_precision(p, nb);
	if (p->flags & FLAG_LEFT_ALIGN)
		return (pf_padding(p, len));
	return (0);
}

static int	pf_nbrpad(t_printf *p, long long unsigned nb)
{
	char *c;

	c = 0;
	(p->flags & FLAG_NEGATIVE) ?  c = "-" : 0;
	(p->flags & FLAG_POSITIVE && p->flags & FLAG_PLUS) ? c = "+" : 0;
	(p->flags & FLAG_POSITIVE && p->flags & FLAG_SPACE) ? c = " " : 0;
	if (p->flags & FLAG_LEFT_ALIGN)
		c != 0 ? pf_buffer(p, c, ft_strlen(c)) : 0;
	else if (p->flags & FLAG_0)
	{
		c != 0 ? pf_buffer(p, c, ft_strlen(c)) : 0;
		pf_padding(p, pf_nbrlen(p, nb));
	}
	else
	{
		pf_padding(p, pf_nbrlen(p, nb));
		c != 0 ? pf_buffer(p, c, ft_strlen(c)) : 0;
	}
	return (0);
}

int		pf_floats(t_printf *p)
{
	long double		nb;
	long long unsigned	nbr;

	if (p->flags & FLAG_LONG_DOUBLE)
		nb = va_arg(p->ap, long double);
	else
		nb = va_arg(p->ap, double);
	(nb >= 0) ? (nbr = nb) : (nbr = -nb);
	(nb >= 0) ? (p->flags |= FLAG_POSITIVE) : (p->flags |= FLAG_NEGATIVE);
	pf_nbrpad(p, nbr);
	return (pf_ftoa(p, nb));
}
