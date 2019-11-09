/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_alloc_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:45:28 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/09 22:42:00 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_getsmall(size_t *total)
{
	t_zone	*zone;
	int		i;
	int		small_n;
	void	*ptr;

	zone = g_params.small;
	dprintf(2, "TINY: %p\n", g_params.small);
	small_n = (SMALLX * g_params.pg_size) / MAXALLOC;
	while (zone)
	{
		i = 0;
		while (i < MAXALLOC)
		{
			if (zone->fargments[i].size)
			{
				ptr = zone->ptr + i * small_n;
				*total += zone->fargments[i].size;
				dprintf(2, "%p - %p : %ld bytes\n",
					ptr, ptr + zone->fargments[i].size,
					zone->fargments[i].size);
			}
			i++;
		}
		zone = zone->next;
	}
}

void	ft_getmeduim(size_t *total)
{
	t_zone	*zone;
	int		i;
	int		medium_n;
	void	*ptr;

	zone = g_params.medium;
	dprintf(2, "SMALL: %p\n", g_params.medium);
	medium_n = (MEDUIMX * g_params.pg_size) / MAXALLOC;
	while (zone)
	{
		i = 0;
		while (i < MAXALLOC)
		{
			if (zone->fargments[i].size)
			{
				*total += zone->fargments[i].size;
				ptr = zone->ptr + i * medium_n;
				dprintf(2, "%p - %p : %ld bytes\n",
					ptr, ptr + zone->fargments[i].size,
						zone->fargments[i].size);
			}
			i++;
		}
		zone = zone->next;
	}
}

void	show_alloc_mem(void)
{
	size_t		total;
	t_fragment	*fr;

	total = 0;
	ft_getsmall(&total);
	ft_getmeduim(&total);
	fr = g_params.larg;
	dprintf(2, "LARGE : %p\n", g_params.larg);
	while (fr)
	{
		dprintf(2, "%p - %p : %ld bytes\n",
			fr->ptr, fr->ptr + fr->size, fr->size);
		fr = fr->next;
	}
	dprintf(2, "Total : %ld bytes\n", total);
}
