/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:56:54 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/08 21:45:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	pf_nbrpad(unsigned int nbr, unsigned int base)
{
	size_t	len;

	len = 1;
	while (nbr >= base && ++len)
		nbr /= base;
	return (len);
}

static char	pf_putbase(t_printf *p, unsigned int nb)
{
	if (nb < 10)
		return (nb + '0');
	if (*p->format == 'X')
		return (nb - 10 + 'A');
	return (nb - 10 + 'a');
}

int		pf_putnbr_u(t_printf *p, unsigned int nbr, unsigned int base)
{
	int	i;
	char	c;
	size_t	len;

	if (!(p->flags & FLAG_LEFT_ALIGN))
	{
		len = pf_nbrpad(nbr, base);
		pf_padding(p, len);
	}
	i = 0;
	if (nbr >= base)
		i += pf_putnbr_u(p, nbr / base, base);
	c = pf_putbase(p, nbr % base);
	i += pf_buffer(p, &c, 1);
	return (i);
}

int		pf_putnbr(t_printf *p, int nbr, unsigned int base)
{
	unsigned int	nb;

	(nbr < 0) ? (nb = -nbr) : (nb = nbr);
	if (p->flags & FLAG_LEFT_ALIGN)
	{
		(nbr < 0) ? pf_buffer(p, "-", 1) : 0;
		(p->flags & FLAG_PLUS) && nbr >= 0 ? pf_buffer(p, "+", 1) : 0;
		if (((p->flags & FLAG_PLUS) && nbr >= 0) || nbr < 0)
			p->width > 0 ? --p->width : 0;
	}
	else if (p->flags & FLAG_0)
	{
		(nbr < 0) ? pf_buffer(p, "-", 1) : 0;
		(p->flags & FLAG_PLUS) && nbr >= 0 ? pf_buffer(p, "+", 1) : 0;
		if (((p->flags & FLAG_PLUS) && nbr >= 0) || nbr < 0)
		{
			p->width > 0 ? --p->width : 0;
			pf_padding(p, pf_nbrpad(nb, base));
		}
	}
	else
	{
		if (((p->flags & FLAG_PLUS) && nbr >= 0) || nbr < 0)
		{
			p->width > 0 ? --p->width : 0;
			pf_padding(p, pf_nbrpad(nb, base));
		}
		(nbr < 0) ? pf_buffer(p, "-", 1) : 0;
		(p->flags & FLAG_PLUS) && nbr >= 0 ? pf_buffer(p, "+", 1) : 0;
	}
	return (pf_putnbr_u(p, nb, base));
}

int		pf_putaddr(t_printf *p, unsigned int addr)
{
	return (pf_putnbr_u(p, addr, 16));
}

