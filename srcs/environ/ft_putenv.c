/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:30:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/15 21:36:34 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putenv(const char *string)
{
	char	*tmp;

	if (!string || !(tmp = ft_strchr(string, '=')))
	{
		errno = EINVAL;
		return (-1);
	}
	*tmp = '\0';
	return (ft_setenv(string, tmp + 1, 1));
}
