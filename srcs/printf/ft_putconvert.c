/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:21:19 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/13 11:19:02 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putformat
**
** diverge format specification
**
** c: character
** s: string
** p: address
** d, i: integer
** u: unsigned integer
** x: unsigned hexadecimal integer (small case)
** X: unsigned hexadecimal integer (capital case)
** %: %
** -----------------------------------------------------------------------------
*/

size_t	ft_putconvert(const char *format, t_fmt attribute, va_list ap)
{
	char	*conv;
	size_t	formatlen;

	formatlen = 0;
	conv = ft_strisf(format + 1, ft_isconvert);
	if (*conv == 'c')
		formatlen = ft_putfmtc(attribute, ap);
	else if (*conv == 's')
		formatlen = ft_putfmts(attribute, ap);
	else if (*conv == 'p')
		formatlen = ft_putfmtp(attribute, ap);
	else if (*conv == 'd' || *conv == 'i')
		formatlen = ft_putfmtdi(attribute, ap);
	else if (*conv == 'u' || *conv == 'x' || *conv == 'X')
		formatlen = ft_putfmtux(attribute, ap, *conv);
	else if (*conv == '%')
		formatlen = ft_putfmtpercent(attribute);
	return (formatlen);
}
