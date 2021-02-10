/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:55:27 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/10 09:23:52 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	if (!(new_lst = malloc(sizeof(t_list))))
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
