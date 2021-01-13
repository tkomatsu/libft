/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:54:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/12 22:29:47 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name)
{
	extern char	**environ;
	int			i;
	int			namelen;

	if (!name || *name == '\0' || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (NULL);
	}
	i = 0;
	namelen = ft_strlen(name);
	while (environ[i])
	{
		if (!ft_strncmp(name, environ[i], namelen))
			return (environ[i] + namelen + 1);
		i++;
	}
	return (NULL);
}
