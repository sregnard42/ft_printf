/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:20:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/07 12:46:49 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_printf
{
	char		buf[1024];
	char		*format;
	va_list		ap;
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	written;
}		t_printf;

enum	e_printf_flags
{
	FLAG_HASH = (1 << 0),
	FLAG_PLUS = (1 << 1),
	FLAG_SPACE = (1 << 2),
	FLAG_LEFT_ALIGN = (1 << 3),
	FLAG_RIGHT_ALIGN = (1 << 4),
	FLAG_WIDTH = (1 << 5),
	FLAG_PRECISION = (1 << 6),
	FLAG_CHAR = (1 << 7),
	FLAG_SHORT = (1 << 8),
	FLAG_LONG = (1 << 9),
	FLAG_LONG_LONG = (1 << 10),
	FLAG_FLOAT = (1 << 11),
	FLAG_DOUBLE = (1 << 12),
	FLAG_LONG_DOUBLE = (1 << 13),
};

int	ft_printf(const char *format, ...);

/*
**	pf_parse_args
*/

int	pf_parse_args(t_printf *p);
int	pf_strlen_until(const char *s, char c);
int	pf_strlen(const char *s);
int 	pf_putchar(const char c);
int	pf_putstr(const char *s);
int	pf_atoi(const char *s);
int	pf_putnbr(int nbr, unsigned int base, short up);
int	pf_putnbr_u(unsigned int nbr, unsigned int base, short up);
int	pf_putaddr(unsigned int p);

#endif
