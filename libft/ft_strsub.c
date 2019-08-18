/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 22:10:48 by sid-bell          #+#    #+#             */
/*   Updated: 2018/10/12 04:51:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	str = NULL;
	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		index = 0;
		while (index < len)
		{
			str[index] = s[index + start];
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
