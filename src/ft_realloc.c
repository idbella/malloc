/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:26:35 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/09 18:42:12 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_realoc(void *ptr, size_t size)
{
	t_zone		*zone;
	t_fragment	*fragment;
	char		type;
	char		newtype;

	if (size <= 0)
		return (NULL);
	zone = ft_getzone(ptr, &fragment, &type);
	if (fragment)
	{
		if (fragment->size == size)
			return (ptr);
		newtype = ft_type(size);
		if (type != newtype)
		{
			ft_free(ptr);
			return (ft_malloc(size));
		}
		else
			fragment->size = size;
		return (ptr);
	}
	return (NULL);
}
