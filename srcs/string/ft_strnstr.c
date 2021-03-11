/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:44:09 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/11 18:35:03 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	searchlen;
	size_t	needlelen;
	char	*ptr;
	size_t	i;

	searchlen = len;
	if (ft_strlen(haystack) < len)
		searchlen = ft_strlen(haystack);
	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	ptr = (char *)haystack;
	i = 0;
	while (*ptr != 0 && i < searchlen - needlelen + 1)
	{
		if (ft_memcmp(ptr, needle, needlelen) == 0)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
