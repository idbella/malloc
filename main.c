/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:24:27 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/09 20:17:52 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{char *f;
	void *p1 = NULL;
	int i = 0;
	while (i < 10)
	{
		 if (i % 1000 == 0)
		 printf("i = %d [%zu]\n", i, g_params.count);
		//p1 = ft_doalloc(1020);
		p1 = ft_malloc(100);
 		bzero(p1, 100);
 		memcpy(p1, "Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.", 99);
 printf("%100s\n\n\n", p1);
		p1 = ft_realoc(p1, 1000);
		f = ft_malloc(5 * i);
		if (i % 2== 0)
		{
			ft_free(f);
			ft_free(p1);
		}
		bzero(p1, 1000);
		memcpy(p1, "Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation,\
 Inc.Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.", 1000);
	 printf("%200s\n\n\n", p1);
		i++;
	}
	show_alloc_mem();
	printf("end with %ld malloc calls / %ld mmap calls\n",g_params.calls, g_params.count);
	return (0);
}
