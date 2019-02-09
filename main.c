/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/09 17:40:27 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	unsigned int i;

	i = 0;
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %+10d |", -42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %+10d |", -42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %0+10d |", -42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %0+10d |", -42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %+-10d |", -42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %+-10d |", -42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %+10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %+10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %0+10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %0+10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %+-10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %+-10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %010d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %010d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| %-10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| %-10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| % 10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| % 10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| % -10d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| % -10d |", 42);
	ft_printf("\n");
	printf("\nTest #%d :\n", ++i);
	printf("| %-10s |", "printf");
	printf("| % 010d |", 42);
	printf("\n");
	ft_printf("| %-10s |", "ft_printf");
	ft_printf("| % 010d |", 42);
	ft_printf("\n");
	return (0);
}
