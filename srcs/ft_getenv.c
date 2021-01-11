/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:54:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/11 23:18:58 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name)
{
	extern char	**environ;
	int			i;
	int			namelen;
	int			valuelen;
	char		*val;

	i = 0;
	namelen = ft_strlen(name);
	while (environ[i])
	{
		if (!ft_strncmp(name, environ[i], namelen))
		{
			valuelen = ft_strlen(environ[i]) - namelen;
			if (!(val = ft_substr(environ[i], namelen + 1, valuelen)))
			{
				errno = ENOMEM;
				return (NULL);
			}
			return (val);
		}
		i++;
	}
	errno = EINVAL;
	return (NULL);
}
