/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:52:22 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 14:16:10 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_small(size_t size)
{
	t_zone		*zone;
	int			i;

	zone = g_params.small;
	while (zone)
	{
		i = 0;
		while (i < MAXALLOC)
		{
			if (!zone->fargments[i].size)
			{
				zone->fargments[i].size = size;
				return (zone->fargments[i].ptr);
			}
			i++;
		}
		zone = zone->next;
	}
	if ((zone = ft_newzone(SMALL, g_params.pg_size * SMALLX)))
	{
		zone->fargments[0].size = size;
		ft_addzone(&g_params.small, zone);
		return (zone->fargments[0].ptr);
	}
	return (NULL);
}
