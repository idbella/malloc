/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:24:45 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/08 19:50:52 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <sys/mman.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define SMALLX 32
# define MEDUIMX 128
# define MAXALLOC 512
# define SMALL 0
# define MEDUIM 1
# define LARGE 2

typedef struct	s_fragment
{
	void				*ptr;
	size_t				size;
	struct s_fragment	*next;
}				t_fragment;

typedef struct	s_zone
{
	t_fragment		fargments[MAXALLOC];
	void			*ptr;
	struct s_zone	*next;
}				t_zone;

typedef struct	s_params
{
	t_zone		*small;
	t_zone		*medium;
	t_fragment	*larg;
	int			pg_size;
	size_t		count;
	size_t		calls;
}				t_params;

void			*ft_malloc(size_t size);
void			*ft_realoc(void *ptr, size_t size);
void			ft_free(void *ptr);
void			*ft_doalloc(size_t size);
t_zone			*ft_newzone(char type, size_t size);
void			ft_addzone(t_zone **lst, t_zone *zone);
void			*ft_small(size_t size);
void			*ft_meduim(size_t size);
void			*ft_large(size_t size);
t_zone			*ft_getzone(void *ptr, t_fragment **fragment, char *type);
char			ft_emptyzone(t_zone *zone);
void			ft_delete_small_zone(t_zone *zone);
void			ft_delete_medium_zone(t_zone *zone);
t_params		g_params;
#endif
