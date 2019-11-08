/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:59:57 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:31:02 by sid-bell         ###   ########.fr       */
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

void	ft_free(void *ptr)
{
	t_fragment	*fragment;
	t_zone		*zone;
	char		type;

	g_params.pg_size = getpagesize();
	if (!g_params.init || !ptr)
		return ;
	zone = ft_getzone(ptr, &fragment, &type);
	if (fragment)
	{
		if (!zone && munmap(fragment->ptr, fragment->size))
		{
			printf("cant free %p\n", fragment->ptr);
			abort();
		}
		fragment->size = 0;
		if (!zone)
			ft_delete_large_fregment(fragment);
		else
		{
			if (type == SMALL && zone != g_params.small)
				if (ft_emptyzone(zone))
					ft_delete_small_zone(zone);
			if (type == MEDUIM && zone != g_params.medium)
				if (ft_emptyzone(zone))
					ft_delete_medium_zone(zone);
		}
		return ;
	}
	printf("adress %p was not allocated\n", ptr);
	abort();
}
