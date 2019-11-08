/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:27:39 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:51:01 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_doalloc(size_t size)
{
	void *ptr;

	if ((ptr = mmap(0, size, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED)
		return (NULL);
	g_params.count++;
	return (ptr);
}

void	ft_preallocat(void)
{
	int	pg_size;

	pg_size = g_params.pg_size;
	g_params.small = ft_newzone(SMALL, pg_size * SMALLX);
	g_params.medium = ft_newzone(MEDUIM, pg_size * MEDUIMX);
}

void	*ft_alloc(size_t size)
{
	size_t		small_n;
	size_t		meduim_n;
	size_t		pg_size;

	pg_size = g_params.pg_size;
	small_n = (SMALLX * pg_size) / MAXALLOC;
	meduim_n = (MEDUIMX * pg_size) / MAXALLOC;
	if (size <= small_n)
		return (ft_small(size));
	if (size <= meduim_n)
		return (ft_meduim(size));
	else
		return (ft_large(size));
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	g_params.pg_size = getpagesize();
	if (size <= 0)
		return (NULL);
	g_params.calls++;
	ptr = ft_alloc(size);
	return (ptr);
}
