/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2018/10/18 19:56:00 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long int		result;
	int				negative;
	unsigned int	i;

	result = 0;
	negative = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	if (negative == 1 && *str == '+')
		str++;
	i = *str - '0';
	while (i < 10)
	{
		result = 10 * result + i;
		str++;
		i = *str - '0';
	}
	if (result < 0)
		return (negative == -1 ? 0 : -1);
	return (result * negative);
}
