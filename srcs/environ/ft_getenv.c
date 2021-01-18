/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:54:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/13 16:56:07 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name)
{
	extern char	**environ;
	int			i;
	int			namelen;

	if (!name || !(namelen = ft_strlen(name)) || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (NULL);
	}
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(name, environ[i], namelen))
			return (&(environ[i][namelen + sizeof("=") - 1]));
		i++;
	}
	return (NULL);
}
