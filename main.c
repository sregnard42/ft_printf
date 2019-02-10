/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/10 18:25:10 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	unsigned int i;

	i = 0;

	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| %3.2d |", 0);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| %3.2d |", 0);
	ft_printf("\n");


	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| %03.2d |", 1);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| %03.2d |", 1);
	ft_printf("\n");

	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |\n", "printf");
	printf("| % 10.5d |", 4242);
	printf("\n");
	ft_printf("| %-10s |\n", "ft_printf");
	ft_printf("| % 10.5d |", 4242);
	ft_printf("\n");

	return (0);
}
