/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:59:53 by sid-bell          #+#    #+#             */
/*   Updated: 2019/08/18 19:44:07 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
# include <sys/mman.h>

typedef struct s_alist
{
	void	*ptr;
	size_t	len;
}				t_alist;

t_list	*alloclst(t_list *lst)
{
	static t_list *l;

	if (lst)
		l = lst;
	return (l);
}

t_alist	*alloclist()
{
	t_alist	*ptr;
	ptr = (t_alist *)mmap(0, sizeof(t_alist), PROT_READ | PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}

void    *ft_malloc(size_t size)
{
	t_list	*l;
	void    *ptr;
	t_alist	*lst;

	if (size <= 0)
		return NULL;
	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	lst = alloclist();
	lst->ptr = ptr;
	lst->len = size;
	l = alloclst(NULL);
	ft_lstadd(&l, ft_lstnew(lst, 0));
	alloclst(l);
	return (ptr);
}
#include <stdio.h>
void	ft_free(void *ptr)
{
	t_list	*l;
	t_alist	*lst;
	size_t	len;

	l = alloclst(NULL);
	while(l)
	{
		lst = l->content;
		if (lst->ptr == ptr)
		{
			len = lst->len;
			break;
		}
		l = l->next;
		//if (!l)
			//return ;	
	}
	if (munmap(ptr, len))
		perror("munmap");
}

int main(int a,char **v)
{
	int i = 2;
	char *f;
	while(i < 50)
	{
		ft_printf_fd(1, "%d\n", i);
		f = ft_malloc(i);
		ft_strncpy(f, "lalalalalalalasdsdgsdgs84gs54dgs4d5g4sd5g4s5dg5sd4g5sd4g", i - 1);
		ft_printf_fd(1, f);
		f[1] = '9';
		ft_free("fsdgdfg");
		i++;
		usleep(10000);
	}
}
