/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:51:45 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/13 11:37:40 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char **env_realloc(char **environ, int len)
{
	char	**ret;

	if (!(ret = ft_calloc(sizeof(char*), (len + 1))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(ret, environ, (len - 1) * sizeof(char*));
	free(environ);
	return (ret);
}

int	overwrite_setenv(const char *name, const char *value, int index)
{
	extern char	**environ;
	char	*new;
	int		namelen;
	int		valuelen;

	namelen = ft_strlen(name);
	valuelen = ft_strlen(value);
	if (!(new = ft_calloc(sizeof(char), namelen + valuelen + 2)))
	{
		errno = ENOMEM;
		return (-1);
	}
	ft_strlcpy(new, name, namelen);
	ft_strlcpy(new + namelen, "=", 1);
	ft_strlcpy(new + namelen + 1, value, valuelen);
	free(environ[index]);
	environ[index] = new;
	return (0);
}

int	new_setenv(const char *name, const char *value, int index)
{
	extern char	**environ;

	if (!(environ = env_realloc(environ, index + 1)))
		return (-1);
	return (overwrite_setenv(name, value, index + 1));
}

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	extern char	**environ;
	int			i;
	int			namelen;
	int			valuelen;

	if (!name || *name == '\0' || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (-1);
	}
	i = 0;
	namelen = ft_strlen(name);
	valuelen = ft_strlen(value);
	while (environ[i])
	{
		if (!ft_strncmp(name, environ[i], namelen))
		{
			if (overwrite)
				return (overwrite_setenv(name, value, i));
			else
				return (0);
		}
		i++;
	}
	return (new_setenv(name, value, i));
}
