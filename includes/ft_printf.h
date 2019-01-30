/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:20:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/30 15:39:20 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);

int ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putaddr(void *p);

int	ft_strlen(char *s);

#endif
