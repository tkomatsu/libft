/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:41:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/21 18:19:45 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	base_check(const char **nptr, int *base)
{
	if ((*base == 0 || *base == 16) && !ft_strncasecmp(*nptr, "0x", 2))
	{
		*base = 16;
		*nptr += 2;
	}
	if (*base == 0)
	{
		*base = 10;
		if (**nptr == '0')
		{
			*nptr += 1;
			*base = 8;
		}
	}
}

int	get_sign(const char **nptr)
{
	if (**nptr == '-')
	{
		*nptr += 1;
		return (-1);
	}
	if (**nptr == '+')
		*nptr += 1;
	return (1);
}

unsigned long	get_num(unsigned long a, const char *n, int b, unsigned long l)
{
	int	c;

	if (ft_isdigit(*n))
		c = *n - '0';
	else
	{
		c = *n - 'a' + 10;
		if (ft_isupper(*n))
			c = *n - 'A' + 10;
	}
	if (c > b)
		errno = EINVAL;
	if (!errno)
		a = a * b + c;
	if (l < a)
		errno = ERANGE;
	return (a);
}

long	return_long(int sign, unsigned long abs)
{
	if (errno == ERANGE && sign < 0)
		return (LONG_MIN);
	else if (errno == ERANGE)
		return (LONG_MAX);
	return ((long)(abs * sign));
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	unsigned long	abs;
	int				sign;
	unsigned long	limit;

	while (ft_isspace(*nptr))
		nptr++;
	sign = get_sign(&nptr);
	base_check(&nptr, &base);
	limit = LONG_MAX;
	if (sign < 0)
		limit--;
	abs = 0;
	while (ft_isalnum(*nptr))
	{
		abs = get_num(abs, nptr, base, limit);
		nptr++;
		if (errno)
			break ;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (return_long(sign, abs));
}
