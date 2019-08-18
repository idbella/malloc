/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 06:05:31 by sid-bell          #+#    #+#             */
/*   Updated: 2019/05/11 00:10:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_csd(t_printf_params *param)
{
	if (*param->format == 's')
	{
		ft_getstr(param);
		return (1);
	}
	else if (*param->format == 'c')
	{
		ft_getchar(param);
		return (1);
	}
	else if (*param->format == 'd')
	{
		ft_getint(param);
		return (1);
	}
	return (0);
}

void	ft_getstr(t_printf_params *param)
{
	char	*str;
	char	*tmp;

	str = va_arg(param->list, char *);
	if (!str)
		str = "(null)";
	tmp = param->str;
	param->str = ft_strjoin(param->str, str);
	free(tmp);
}

void	ft_getint(t_printf_params *param)
{
	int		result;
	char	*str;
	char	*tmp;

	result = va_arg(param->list, int);
	str = ft_itoa(result);
	tmp = param->str;
	param->str = ft_strjoin(param->str, str);
	free(tmp);
	free(str);
}

void	ft_getchar(t_printf_params *param)
{
	char	*str;
	char	*tmp;

	str = (char *)ft_strnew(1);
	str[0] = (char)va_arg(param->list, int);
	str[1] = '\0';
	tmp = param->str;
	param->str = ft_strjoin(param->str, str);
	free(tmp);
}
