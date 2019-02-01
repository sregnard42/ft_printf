/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/01 18:13:29 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned int nb)
{
	if (nb < 10)
		return (ft_putchar(nb + '0'));
	return (ft_putchar(nb - 10 + 'a'));
}

int	ft_putnbr_u(unsigned int nbr, unsigned int base)
{
	int	i;

	i = 0;
	if (nbr >= base)
		i += ft_putnbr_u(nbr / base, base);
	i += ft_putbase(nbr % base);
	return (i);
}

int	ft_putnbr(int nbr, unsigned int base)
{
	unsigned int	nb;

	if (nbr < 0)
		ft_putchar('-');
	nb = nbr > 0 ? nbr : -nbr;
	return (ft_putnbr_u(nb, base));
}
