/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/05 18:14:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putbase(unsigned int nb, short up)
{
	if (nb < 10)
		return (pf_putchar(nb + '0'));
	return (pf_putchar(nb - 10 + 'a' + up * ('A' - 'a')));
}

int	pf_putnbr_u(unsigned int nbr, unsigned int base, short up)
{
	int	i;

	i = 0;
	if (nbr >= base)
		i += pf_putnbr_u(nbr / base, base, up);
	i += pf_putbase(nbr % base, up);
	return (i);
}

int	pf_putnbr(int nbr, unsigned int base, short up)
{
	unsigned int	nb;

	if (nbr < 0)
		pf_putchar('-');
	nb = nbr > 0 ? nbr : -nbr;
	return (pf_putnbr_u(nb, base, up));
}
