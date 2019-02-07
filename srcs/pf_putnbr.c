/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/07 13:35:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putbase(t_printf *p, unsigned int nb, short up)
{
	if (nb < 10)
		return (pf_putchar(p, nb + '0'));
	return (pf_putchar(p, nb - 10 + 'a' + up * ('A' - 'a')));
}

int	pf_putnbr_u(t_printf *p, unsigned int nbr, unsigned int base, short up)
{
	int	i;

	i = 0;
	if (nbr >= base)
		i += pf_putnbr_u(p, nbr / base, base, up);
	i += pf_putbase(p, nbr % base, up);
	return (i);
}

int	pf_putnbr(t_printf *p, int nbr, unsigned int base, short up)
{
	unsigned int	nb;

	if (nbr < 0)
		pf_putchar(p, '-');
	nb = nbr > 0 ? nbr : -nbr;
	return (pf_putnbr_u(p, nb, base, up));
}
