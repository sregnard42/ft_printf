/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:29:54 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/11 14:57:01 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	pf_atoi(const char *s)
{
	unsigned int nb;

	nb = 0;
	while (ft_isdigit(*s))
			nb = nb * 10 + *s++ - '0';
	return (nb);
}

unsigned int pf_itoa(t_printf *p, long long unsigned nb)
{
	size_t	len;
	char	c;

	len = 0;
	if (nb >= 10)
		len += pf_itoa(p, nb / 10);
	nb %= 10;
	c = nb + '0';
	len += pf_buffer(p, &c, 1);
	return (len);
}
