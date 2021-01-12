/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:54:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/12 21:42:12 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name)
{
	extern char	**environ;
	int			i;
	int			namelen;

	i = 0;
	namelen = ft_strlen(name);
	while (environ[i])
	{
		if (!ft_strncmp(name, environ[i], namelen))
			return (environ[i] + namelen + 1);
		i++;
	}
	errno = EINVAL;
	return (NULL);
}
