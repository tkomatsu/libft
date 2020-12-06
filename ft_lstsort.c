/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/06 07:43:32 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_merge(t_list *a, t_list *b, int (*f)(void*, void*))
{
	t_list	result;
	t_list	*x;

	x = &result;
	while (a != NULL && b != NULL)
	{
		if (f(a->content, b->content) > 0)
		{
			x->next = b;
			x = x->next;
			b = b->next;
		}
		else
		{
			x->next = a;
			x = x->next;
			a = a->next;
		}
	}
	if (a == NULL)
		x->next = b;
	else
		x->next = a;
	return (result.next);
}

static t_list	*ft_mergesort(t_list *lst, int (*f)(void*, void*))
{
	t_list	*a;
	t_list	*b;
	t_list	*x;

	if (!lst || !lst->next)
		return (lst);
	a = lst;
	b = lst->next;
	if (b != NULL)
		b = b->next;
	while (b != NULL)
	{
		a = a->next;
		b = b->next;
		if (b != NULL)
			b = b->next;
	}
	x = a->next;
	a->next = NULL;
	return (ft_merge(ft_mergesort(lst, f), ft_mergesort(x, f), f));
}

void			ft_lstsort(t_list **lst, int (*f)(void*, void*))
{
	t_list	*result;

	if (!lst || !*lst)
		return ;
	result = ft_mergesort(*lst, f);
	*lst = result;
}
