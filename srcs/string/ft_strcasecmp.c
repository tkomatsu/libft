/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:01:49 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/27 15:09:22 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]))
	{
		if (!ft_tolower(s1[i]) && !ft_tolower(s2[i]))
			return (0);
		i++;
	}
	return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
}
