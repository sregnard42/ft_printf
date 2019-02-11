/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/11 15:13:57 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int ac, char **av)
{
	unsigned int	i;
	long double	d;	

	i = 0;

	d = 6.2222222222222222;
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| %10.16Lf |", d);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| %10.16Lf |", d);
	ft_printf("\n");

	d = 6.4444444444444444;
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| %10.16Lf |", d);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| %10.16Lf |", d);
	ft_printf("\n");

	d = 6.2222;
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| %10.16Lf |", d);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| %10.16Lf |", d);
	ft_printf("\n");
	return (0);
}
