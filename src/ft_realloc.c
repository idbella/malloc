/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:26:35 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/31 23:58:27 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	t_fragment	*fragment;
	char		type;
	char		newtype;
	void		*newptr;

	if (size <= 0)
		return (NULL);
	ft_getzone(ptr, &fragment, &type);
	if (size == 0 && ptr)
	{
		ft_free(ptr);
		return (NULL);
	}
	if (size && !ptr)
		return (ft_malloc(size));
	if (fragment)
	{
		if (fragment->size == size)
			return (ptr);
		newtype = ft_type(size);
		if (type != newtype)
		{
			newptr = ft_malloc(size);
			ft_memcpy(newptr, ptr, size);
			ft_free(ptr);
			return (newptr);
		}
		else
			fragment->size = size;
		return (ptr);
	}
	return (NULL);
}
