/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:56:54 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/09 18:04:12 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_nbrlen(t_printf *p, unsigned long long nb, unsigned int base)
{
	size_t		len;

	len = 1;
	if (!(p->flags & FLAG_LEFT_ALIGN) && !(p->flags & FLAG_0)
			&& (p->flags & FLAG_NEGATIVE
			|| (p->flags & FLAG_POSITIVE && p->flags & FLAG_PLUS)))
		++len;
	while (nb >= base && ++len)
		nb /= base;
	return (len);
}

static int	pf_putnbr(t_printf *p, unsigned long long nb, unsigned int base)
{
	char	c;

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
		return (pf_nbrlen(p, nb, base));
	return (0);
}

static int	pf_nbrpad(t_printf *p, unsigned long long nb, unsigned int base)
{
	char c;

	c = 0;
	if (p->flags & FLAG_NEGATIVE)
		c = '-';
	else if (p->flags & FLAG_POSITIVE && p->flags & FLAG_PLUS)
		c = '+';
	else if (p->flags & FLAG_POSITIVE && p->flags & FLAG_SPACE)
		c = ' ';
	if (p->flags & FLAG_LEFT_ALIGN)
		c != 0 ? pf_buffer(p, &c, 1) : 0;
	else if (p->flags & FLAG_0)
	{
		c != 0 ? pf_buffer(p, &c, 1) : 0;
		pf_padding(p, pf_nbrlen(p, nb, base));
	}
	else
	{
		pf_padding(p, pf_nbrlen(p, nb, base));
		c != 0 && c != ' ' ? pf_buffer(p, &c, 1) : 0;
	}
	return (0);
}

int		pf_nb_signed(t_printf *p, long long nbr, unsigned int base)
{
	unsigned long long	nb;

	nb = nbr >= 0 ? nbr : -nbr;	
	p->flags |= nbr >= 0 ? FLAG_POSITIVE : FLAG_NEGATIVE;
	pf_nbrpad(p, nb, base);
	return (pf_putnbr(p, nb, base));
}

int		pf_nb_unsigned(t_printf *p, unsigned long long nb,
		unsigned int base)
{
	pf_nbrpad(p, nb, base);
	return (pf_putnbr(p, nb, base));
}
