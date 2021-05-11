/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:16:02 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/05/11 11:49:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ch;

	ch = (char *)s;
	i = ft_strlen(s);
	while (i > 0 && s[i] != (char)c)
		i--;
	if (ch[i] == (char)c)
		return (ch + i);
	return (NULL);
}
