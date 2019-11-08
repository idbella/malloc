/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:55:09 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:30:29 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_large(size_t size)
{
	void		*ptr;
	t_fragment	*fragment;
	t_fragment	*lst;

	ptr = NULL;
	if ((fragment = ft_doalloc(sizeof(t_fragment))))
	{
		if ((ptr = ft_doalloc(size)))
		{
			fragment->next = NULL;
			fragment->size = size;
			fragment->ptr = ptr;
			if ((lst = g_params.larg))
			{
				while (lst->next)
					lst = lst->next;
				lst->next = fragment;
			}
			else
				g_params.larg = fragment;
		}
		else
			munmap(fragment, sizeof(t_fragment));
	}
	return (ptr);
}
