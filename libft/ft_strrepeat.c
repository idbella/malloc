/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 06:18:08 by sid-bell          #+#    #+#             */
/*   Updated: 2018/10/16 06:18:10 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepeat(char const *str, size_t count)
{
	char *new;

	new = NULL;
	if (str && count)
	{
		if ((new = (char *)malloc(sizeof(char) *
			(ft_strlen(str) * count))) == NULL)
			return (NULL);
		while (count--)
		{
			ft_strcat(new, str);
		}
	}
	return (new);
}
