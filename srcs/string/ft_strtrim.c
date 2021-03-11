/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:21:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/11 18:36:50 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_strchrset(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) != NULL)
			i++;
		else
			return (i);
	}
	return (i);
}

static int	ft_strrchrset(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strrchr(set, s1[i]) != NULL)
			i--;
		else
			return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		start;
	int		end;
	size_t	len;

	if (!s1)
		return (NULL);
	start = ft_strchrset(s1, set);
	end = ft_strrchrset(s1, set);
	len = (size_t)(end - start + 1);
	if (!s1[start])
		len = 0;
	ans = malloc((len + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ft_memcpy(ans, s1 + start, len);
	ans[len] = '\0';
	return (ans);
}
