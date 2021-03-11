/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:28:11 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/11 18:26:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *s)
{
	double	val;
	double	power;
	int		i;
	int		sign;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	sign = 1;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	val = 0.0;
	while (ft_isdigit(s[i]))
		val = 10.0 * val + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	power = 1.0;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i++] - '0');
		power *= 10.0;
	}
	return (sign * val / power);
}
