/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:23:36 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/05 17:46:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf	p;
	size_t		len;

	p.written = 0;
	p.format = (char *)format;
	va_start(p.ap, format);
	while (p.format && *p.format)
	{
		len = pf_strlen_until(p.format, '%');
		p.written += write(1, p.format, len);
		p.format += len;
		if (p.format && *p.format && *p.format == '%')
		{
			p.written += pf_parse_args(&p);
			if (p.format && *p.format)
				++(p.format);
		}
	}
	va_end(p.ap);
	return (p.written);
}
