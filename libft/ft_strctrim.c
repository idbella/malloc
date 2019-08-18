/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 23:19:05 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/12 22:27:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *str, char c)
{
	int		start;
	int		end;
	char	*new;
	int		len;

	start = 0;
	while (str[start] == c)
		start++;
	end = ft_strlen(str) - 1;
	while (end > 0 && str[end] == c)
		end--;
	len = end - start + 1;
	if (!(new = ft_strsub(str, start, len)))
		return (NULL);
	return ((char *)new);
}
