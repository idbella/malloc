/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getzone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:54:10 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:30:06 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_zone	*ft_find(void *ptr, t_zone *zone, t_fragment **fragment)
{
	int i;

	while (zone)
	{
		i = 0;
		while (i < MAXALLOC)
		{
			*fragment = &zone->fargments[i];
			if ((*fragment)->ptr == ptr)
				return (zone);
			i++;
		}
		zone = zone->next;
	}
	return (NULL);
}

t_zone	*ft_getzone(void *ptr, t_fragment **fragment, char *type)
{
	t_zone	*zone;

	zone = g_params.small;
	*type = SMALL;
	if ((zone = ft_find(ptr, zone, fragment)))
		return (zone);
	*type = MEDUIM;
	zone = g_params.medium;
	if ((zone = ft_find(ptr, zone, fragment)))
		return (zone);
	*type = LARGE;
	*fragment = g_params.larg;
	while (*fragment)
	{
		if ((*fragment)->ptr == ptr)
			return (NULL);
		*fragment = (*fragment)->next;
	}
	return (NULL);
}
