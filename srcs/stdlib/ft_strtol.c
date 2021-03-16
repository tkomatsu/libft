/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:45:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/16 16:13:55 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	define_base(const char *s, int *base)
{
	int	i;

	i = 0;
	if ((*base == 0 || *base == 16) && *s == '0'
		&& (*(s + 1) == 'x' || *(s + 1) == 'X'))
	{
		*base = 16;
		i = 2;
	}
	if (*base == 0)
	{
		*base = 10;
		if (*s == '0')
			*base = 8;
	}
	return (i);
}

int	get_sign(const char *s)
{
	if (*s == '-')
		return (-1);
	return (1);
}

int	getnum(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_isupper(c))
		return (c - 'A' + 10);
	return (c - 'a' + 10);
}

long	ft_strtol(const char *s, char **endptr, int base)
{
	int				sign;
	int				c;
	unsigned long	limit;
	unsigned long	ret;

	while (ft_isspace(*s))
		s++;
	sign = get_sign(s);
	if (*s == '-' || *s == '+')
		s++;
	s += define_base(s, &base);
	limit = LONG_MAX;
	if (sign < 0)
		limit--;
	while (*s)
	{
		if (ft_isalnum(*s))
			c = getnum(*s);
		if (!ft_isalnum(*s) || c >= base)
			break ;
		if (ret > limit)
		{
			errno = ERANGE;
			break ;
		}
		else
			ret = ret * base + c;
		s++;
	}
	if (endptr)
		*endptr = (char *)s;
	if (errno == ERANGE)
	{
		if (sign < 0)
			return (LONG_MIN);
		return (LONG_MAX);
	}
	if (sign < 0)
		ret *= -1;
	return (ret);
}
