/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:24:27 by sid-bell          #+#    #+#             */
/*   Updated: 2019/06/18 10:45:51 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>

int	main(void)
{
	char *str;

	if ((str = (char *)malloc(1)))
	{
		printf("result = : %p\n", str);
		str = malloc(1);
		printf("result = : %p\n", str);
	}
	return (0);
}
