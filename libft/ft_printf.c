/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 02:28:02 by sid-bell          #+#    #+#             */
/*   Updated: 2019/08/13 18:42:21 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_join(int fd, char *format, ...)
{
	t_printf_params	*param;
	char			*ptr;

	param = ft_init_printf((char *)format);
	va_start(param->list, format);
	while (*param->format)
	{
		if (*param->format == '%')
			while (*(++param->format))
			{
				if (ft_csd(param))
					break ;
			}
		else
			ft_append(param);
		param->format++;
	}
	ft_putstr_fd(param->str, fd);
	va_end(param->list);
	ptr = param->str;
	free(param);
	return (ptr);
}

t_printf_params	*ft_init_printf(char *format)
{
	t_printf_params *param;

	param = (t_printf_params *)malloc(sizeof(t_printf_params));
	param->format = format;
	param->str = ft_strnew(0);
	return (param);
}

void			ft_append(t_printf_params *param)
{
	char	*str;
	char	*tmp;

	str = ft_strnew(1);
	str[0] = *param->format;
	str[1] = '\0';
	tmp = param->str;
	param->str = ft_strjoin(param->str, str);
	free(tmp);
	free(str);
}
