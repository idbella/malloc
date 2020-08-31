/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:48:19 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/31 23:35:16 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dest;
	char *source;

	dest = (char *)dst;
	source = (char *)src;
	while (n-- > 0)
	{
		*dest = *source;
		dest++;
		source++;
	}
	return (dst);
}
