/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:20:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/01 17:25:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_strlen(const char *s);
int 	ft_putchar(const char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int nbr, unsigned int base);
int	ft_putnbr_u(unsigned int nbr, unsigned int base);
int	ft_putaddr(unsigned int p);

#endif
