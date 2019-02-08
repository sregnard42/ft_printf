/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:56:54 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/08 17:57:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_putbase(t_printf *p, unsigned int nb)
{
	if (nb < 10)
		return (pf_putchar(p, nb + '0'));
	if (*p->format == 'X')
		return (pf_putchar(p, nb - 10 + 'A'));
	return (pf_putchar(p, nb - 10 + 'a'));
}

int		pf_putnbr_u(t_printf *p, unsigned int nbr, unsigned int base)
{
	int	i;

	i = 0;
	if (nbr >= base)
		i += pf_putnbr_u(p, nbr / base, base);
	i += pf_putbase(p, nbr % base);
	return (i);
}

int		pf_putnbr(t_printf *p, int nbr, unsigned int base)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		pf_putchar(p, '-');
		nb = -nbr;
		return (pf_putnbr_u(p, nb, base) + 1);
	}
	nb = nbr;
	return (pf_putnbr_u(p, nb, base));
}

int	pf_putaddr(t_printf *p, unsigned int addr)
{
	return (pf_putnbr_u(p, addr, 16));
}

