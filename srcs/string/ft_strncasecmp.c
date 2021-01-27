/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:01:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/27 15:13:46 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ft_tolower(s1[i]) == ft_tolower(s2[i]))
	{
		if (i == n - 1 || ft_tolower(s1[i]) == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)ft_tolower(s1[i])
			- (unsigned char)ft_tolower(s2[i]));
}
