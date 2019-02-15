/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/15 12:41:44 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main(int ac, char **av)
{
	int		i;
	unsigned long	u;
	long double	d;

	i = 0;
	d = LDBL_MIN;
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("%-10Lf", d);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("%-10Lf", d);
	ft_printf("\n");
	return (0);
}
