/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:58:39 by sid-bell          #+#    #+#             */
/*   Updated: 2018/10/18 21:44:12 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill(char *str, unsigned int n, int lenght, int sign)
{
	while (--lenght >= 0)
	{
		if (sign && lenght == 0)
		{
			str[0] = '-';
			break ;
		}
		str[lenght] = (n % 10) + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			lenght;
	unsigned int	un;

	un = n < 0 ? -n : n;
	lenght = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	str[lenght] = '\0';
	fill(str, un, lenght, n < 0);
	return (str);
}
