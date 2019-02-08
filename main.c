/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/08 17:35:18 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("printf :\n");
	printf("| %10d |", -347);
	printf("\n");
	printf("ft_printf :\n");
	ft_printf("| %10d |", -347);
	printf("\n");
	
	printf("\n");

	printf("printf :\n");
	printf("%o", -347);
	printf("\n");
	printf("ft_printf :\n");
	ft_printf("%o", -347);
	printf("\n");
	
	printf("\n");

	printf("printf :\n");
	printf("%x", -347);
	printf("\n");
	printf("ft_printf :\n");
	ft_printf("%x", -347);
	printf("\n");
	
	printf("\n");

	printf("printf :\n");
	printf("%X", -347);
	printf("\n");
	printf("ft_printf :\n");
	ft_printf("%X", -347);
	printf("\n");
	return (0);
}
