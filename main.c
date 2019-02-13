/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/13 15:40:08 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main(int ac, char **av)
{
	unsigned int	i;
	unsigned long	u;
	long double		d;

	i = 0;
	d = 4.3f / 2.3f;
	printf("\nTest #%d %%#o:\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| {%#o} |", 0);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| {%#o} |", 0);
	ft_printf("\n");
	printf("\nTest #%d %%#.o:\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("%#.o %#.0o", 0, 0);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("%#.o %#.0o", 0, 0);
	ft_printf("\n");
	printf("\nTest #%d %%.3o (1):\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("%#.3o", 1);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("%#.3o", 1);
	ft_printf("\n");
	printf("\nTest #%d %%.3o (0):\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("%#.3o", 0);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("%#.3o", 0);
	ft_printf("\n");
	return (0);
}
