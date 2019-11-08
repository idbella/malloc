/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:59:57 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:48:40 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_delete_large_fregment(t_fragment *fragment)
{
	t_fragment	*lst;
	t_fragment	*prev;

	prev = NULL;
	lst = g_params.larg;
	while (lst)
	{
		if (lst == fragment)
		{
			if (prev)
				prev->next = lst->next;
			else
				g_params.larg = lst->next;
			munmap(lst, sizeof(t_fragment));
			return ;
		}
		prev = lst;
		lst = lst->next;
	}
}

void	ft_free(void *ptr)
{
	t_fragment	*fragment;
	t_zone		*zone;
	char		type;

	if (!ptr || !(g_params.pg_size = getpagesize()))
		return ;
	zone = ft_getzone(ptr, &fragment, &type);
	if (fragment)
	{
		if (!zone)
			munmap(fragment->ptr, fragment->size);
		fragment->size = 0;
		if (!zone)
			ft_delete_large_fregment(fragment);
		else if (ft_emptyzone(zone))
		{
			if (type == SMALL && zone != g_params.small)
				ft_delete_small_zone(zone);
			if (type == MEDUIM && zone != g_params.medium)
				ft_delete_medium_zone(zone);
		}
		return ;
	}
}
