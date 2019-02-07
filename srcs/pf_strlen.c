/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:37:10 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/04 17:57:59 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pf_strlen_until(const char *s, char c)
{
	const char	*start = s;
	
	while (s && *s && *s != c)
		++s;
	return (s - start);
}

int	pf_strlen(const char *s)
{
	return (pf_strlen_until(s, '\0'));
}
