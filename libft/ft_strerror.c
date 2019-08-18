/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/15 14:22:53 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strerror(int error)
{
	if (error > 106)
		return (NULL);
	if (error >= 88)
		return (ft_errors_88_106(error));
	else if (error >= 66)
		return (ft_errors_66_87(error));
	else if (error >= 44)
		return (ft_errors_44_65(error));
	else if (error >= 22)
		return (ft_errors_22_43(error));
	return (ft_errors_0_21(error));
}
