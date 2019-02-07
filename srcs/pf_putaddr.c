/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:09:59 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/07 13:27:38 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putaddr(t_printf *p, unsigned int addr)
{
	return (pf_putnbr_u(p, addr, 16, 0));
}
