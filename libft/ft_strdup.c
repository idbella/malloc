/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 01:50:45 by sid-bell          #+#    #+#             */
/*   Updated: 2018/10/14 17:12:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		lenght;
	char	*new_str;

	lenght = ft_strlen(s1);
	if (!(new_str = (char *)malloc(sizeof(char) * lenght + 1)))
		return (0);
	ft_strcpy(new_str, s1);
	return (new_str);
}
