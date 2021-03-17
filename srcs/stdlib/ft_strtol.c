/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:41:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/17 15:16:25 by tkomatsu         ###   ########.fr       */
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

unsigned long	get_num(unsigned long abs, const char *nptr, int base, unsigned long limit)
{
	int	c;

	if (ft_isdigit(*nptr))
		c = *nptr - '0';
	else
	{
		c = *nptr - 'a' + 10;
		if (ft_isupper(*nptr))
			c = *nptr - 'A' + 10;
	}
	abs = abs * base + c;
	if (limit < abs)
		errno = ERANGE;
	return (abs);
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
	if (errno == ERANGE && sign < 0)
		return (LONG_MIN);
	else if (errno == ERANGE)
		return (LONG_MAX);
	return ((long)(abs * sign));
}
