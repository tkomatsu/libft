/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:12:54 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/12 17:15:25 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *list_ptr, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (i != nbr && list_ptr)
		list_ptr = list_ptr->next;
	return (list_ptr);
}
