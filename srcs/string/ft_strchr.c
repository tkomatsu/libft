/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:09:37 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/05/10 20:39:26 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ch;

	ch = (char *)s;
	i = 0;
	while (ch[i] != 0 && ch[i] != (char)c)
		i++;
	if (ch[i] == (char)c)
		return (ch + i);
	return (NULL);
}
