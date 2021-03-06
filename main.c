/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:24:27 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/31 23:59:00 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
//#include <stdlib.h>

int	main(void)
{
	char *str;
	char *test;

	test = "abcdefghij";
	str = ft_malloc(10);
	strcpy(str, test);
	printf("%p\n", str);
	assert(!strcmp(str, test));
	str = ft_realloc(str, 5);
	printf("%p\n", str);
	return (0);
}
