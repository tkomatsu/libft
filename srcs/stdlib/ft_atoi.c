/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:24:54 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/11 18:29:28 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign *= get_sign(str[i]);
		i++;
	}
	if ('0' <= str[i] && str[i] <= '9')
	{
		while ('0' <= str[i] && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
	}
	result *= sign;
	return ((int)result);
}
