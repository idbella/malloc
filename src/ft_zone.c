/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:48:43 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:48:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

char	ft_emptyzone(t_zone *zone)
{
	t_fragment	*fragment;
	int			i;

	i = 0;
	fragment = zone->fargments;
	while (i < MAXALLOC)
	{
		if (fragment[i].size)
			return (0);
		i++;
	}
	return (1);
}

void	ft_delete_zone(t_zone *zone, t_zone *lst)
{
	t_zone		*prev;

	prev = NULL;
	while (lst)
	{
		if (lst == zone)
		{
			if (prev)
				prev->next = lst->next;
			munmap(lst, sizeof(t_zone));
			return ;
		}
		prev = lst;
		lst = lst->next;
	}
}

void	ft_delete_small_zone(t_zone *zone)
{
	int			i;

	i = 0;
	while (i < MAXALLOC)
	{
		munmap(zone->ptr, SMALLX * g_params.pg_size);
		i++;
	}
	ft_delete_zone(zone, g_params.small);
}

void	ft_delete_medium_zone(t_zone *zone)
{
	int			i;

	i = 0;
	while (i < MAXALLOC)
	{
		munmap(zone->ptr, MEDUIMX * g_params.pg_size);
		i++;
	}
	ft_delete_zone(zone, g_params.medium);
}
