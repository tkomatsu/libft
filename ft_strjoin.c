/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:54:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/11 09:02:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	anslen;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	anslen = ft_strlen(s1) + ft_strlen(s2);
	if (!(ans = ft_calloc(anslen + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		ans[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != 0)
	{
		ans[i + k] = s2[k];
		k++;
	}
	return (ans);
}
