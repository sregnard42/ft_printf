/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/08 16:15:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putbase(t_printf *p, unsigned int nb)
{
	if (nb < 10)
		return (pf_putchar(p, nb + '0'));
	if (*p->format == 'X')
		return (pf_putchar(p, nb - 10 + 'A'));
	return (pf_putchar(p, nb - 10 + 'a'));
}

int	pf_putnbr_u(t_printf *p, unsigned int nbr, unsigned int base)
{
	int	i;

	i = 0;
	if (nbr >= base)
		i += pf_putnbr_u(p, nbr / base, base);
	i += pf_putbase(p, nbr % base);
	return (i);
}

int	pf_putnbr(t_printf *p, int nbr, unsigned int base)
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
