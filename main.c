/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/07 15:07:25 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s;
	size_t	len;

	len = 50;
	s = (char *)malloc(sizeof(char) * len + 1);
	ft_memset(s, 'a', len);
	s[len] = '\0';
//	printf("%-9s: %-5%\n", "printf");
//	ft_printf("%-9s: %-5%\n", "ft_printf");
	printf("%-10s :\n", "printf");
	printf("{%0+10d}", 42);
	printf("\n");
	ft_printf("%-10s :\n", "ft_printf");
	ft_printf("{%0+10d}", 42);
	printf("\n");
	return (0);
}
