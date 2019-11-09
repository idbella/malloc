/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_alloc_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:45:28 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/09 20:14:16 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_getsmall(void)
{
	t_zone	*zone;
	int		i;
	int		small_n;
	void	*ptr;

	zone = g_params.small;
	printf("TINY: %p\n", g_params.small);
	small_n = (SMALLX * g_params.pg_size) / MAXALLOC;
	while (zone)
	{
		i = 0;
		while (i < MAXALLOC)
		{
			if (zone->fargments[i].size)
			{
				ptr = zone->ptr + i * small_n;
				printf("%p - %p : %ld bytes\n", ptr, ptr + zone->fargments[i].size, zone->fargments[i].size);
			}
			i++;
		}
		zone = zone->next;
	}
}

void	ft_getmeduim(void)
{
	t_zone	*zone;
	int		i;
	int		medium_n;
	void	*ptr;

	zone = g_params.medium;
	printf("SMALL: %p\n", g_params.medium);
	medium_n = (MEDUIMX * g_params.pg_size) / MAXALLOC;
	while (zone)
	{
		i = 0;
		while (i < MAXALLOC)
		{
			if (zone->fargments[i].size)
			{
				ptr = zone->ptr + i * medium_n;
				printf("%p - %p : %ld bytes\n", ptr, ptr + zone->fargments[i].size, zone->fargments[i].size);
			}
			i++;
		}
		zone = zone->next;
	}
}

void	show_alloc_mem(void)
{
	ft_getsmall();
	ft_getmeduim();
}
