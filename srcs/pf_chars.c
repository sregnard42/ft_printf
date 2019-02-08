/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:59:04 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/08 19:04:07 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(t_printf *p, const char c)
{
	pf_padding(p, 1);
	return (pf_buffer(p, &c, 1));
}

int	pf_putstr(t_printf *p, const char *s)
{
	if (!s)
		s = "(null)";
	pf_padding(p, ft_strlen(s));
	return (pf_buffer(p, s, ft_strlen(s)));
}
