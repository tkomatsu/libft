/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:23:50 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/28 11:17:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(char *s, const char *delim, char **last)
{
	char	*tok;

	if (!s && !(s = *last))
		return (NULL);
	while (*s && ft_strchr(delim, *s))
		s++;
	if (*s == '\0')
		return (*last = NULL);
	tok = s;
	while (*s && !ft_strchr(delim, *s))
		s++;
	if (*s == '\0')
		s = NULL;
	else
	{
		*s = '\0';
		s++;
		while (*s && ft_strchr(delim, *s))
			s++;
		if (*s == '\0')
			s = NULL;
	}
	*last = s;
	return (tok);
}
