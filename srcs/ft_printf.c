/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:23:36 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/07 14:28:42 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_buffer(t_printf *p, const char *s, size_t len)
{
	size_t	i;

	i = 0;
	if (p->index + len >= PF_BUFF_SIZE)
	{
		p->written += write(1, p->buf, p->index);
		ft_bzero(p->buf, PF_BUFF_SIZE);
		p->index = 0;
	}
	while (i < len && i < PF_BUFF_SIZE)
		p->buf[p->index++] = *(s + i++);
	if (i < len)
		pf_buffer(p, s + i, len - i);
	return (len);	
}

int			ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.format = (char *)format;
	va_start(p.ap, format);
	while (p.format && *p.format)
	{
		
		while (p.format && *p.format && *p.format != '%')
			p.buf[p.index++] = *p.format++;
		if (p.format && *p.format && *p.format == '%')
		{
			pf_parse_args(&p);
			if (p.format && *p.format)
				++(p.format);
		}
	}
	p.written += write(1, p.buf, p.index);
	va_end(p.ap);
	return (p.written);
}
