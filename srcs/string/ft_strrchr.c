/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:16:02 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/11 18:35:16 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ch;

	ch = (char *)s;
	i = (int)ft_strlen(s);
	while (i > 0 && s[i] != (char)c)
		i--;
	if (ch[i] == (char)c)
		return (ch + i);
	return (NULL);
}
