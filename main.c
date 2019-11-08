/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:24:27 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:37:52 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	void *p1 = NULL;
	int i = 0;
	getchar();
	while (i < 10000)
	{
		printf("i = %d [%zu]\n", i, g_params.count);
		p1 = ft_malloc(1025);
		//p2 = ft_malloc(10);
		bzero(p1, 100);
		memcpy(p1, "Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.", 99);
		//printf("%p - %p:|%s|\n", p2, p1, p1);
		//ft_free(p1);
		//ft_free(p2);
		i++;
	}
	printf("end with %ld malloc calls / %ld mmap calls\n",g_params.calls, g_params.count);
	getchar();
	return (0);
}
