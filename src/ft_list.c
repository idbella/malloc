/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:30:49 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:29:33 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_zone	*ft_newzone(char type, size_t size)
{
	t_zone		*zone;
	int			i;
	int			small_n;
	int			meduim_n;

	if ((zone = ft_doalloc(sizeof(t_zone))))
	{
		small_n = (SMALLX * g_params.pg_size) / MAXALLOC;
		meduim_n = (MEDUIMX * g_params.pg_size) / MAXALLOC;
		i = 0;
		zone->ptr = ft_doalloc(size);
		while (i < MAXALLOC)
		{
			zone->fargments[i].ptr = zone->ptr +
				i * (type == SMALL ? small_n : meduim_n);
			zone->fargments[i].next = NULL;
			zone->fargments[i].size = 0;
			i++;
		}
		zone->next = NULL;
	}
	return (zone);
}

void	ft_addzone(t_zone **lst, t_zone *zone)
{
	t_zone *zn;

	if (!lst)
		return ;
	zn = *lst;
	if (zn)
	{
		while (zn->next)
			zn = zn->next;
		zn->next = zone;
	}
	else
		*lst = zone;
}
