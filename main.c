/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:26:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/01 15:35:21 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char a = 'c';
	char *s = "Hello";
	
	printf("printf %%p\t: %p\n", (void *)s);
	ft_printf("ft_printf %%p\t: %p\n\n", (void *)s);

	printf("printf %%#lx\t: %#lx\n", (unsigned long)s);
	ft_printf("ft_printf %%#lx\t: %#lx\n\n", (unsigned long)s);

	printf("printf %%x\t: %x\n", (unsigned int)s);
	ft_printf("ft_printf %%x\t: %x\n\n", (unsigned int)s);

	printf("printf %%o\t: %o\n", (unsigned int)s);
	ft_printf("ft_printf %%o\t: %o\n\n", (unsigned int)s);

	return (0);
}
