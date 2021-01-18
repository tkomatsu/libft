/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:41:23 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/16 21:10:04 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_printf
**
** translate format specification
**
** 1. get attribute of format
** 2. put format specification and return output length
** -----------------------------------------------------------------------------
*/

size_t	ft_putformat(const char *format, va_list ap)
{
	size_t	formatlen;
	t_fmt	attribute;

	attribute = ft_getattribute(format, ap);
	formatlen = ft_putconvert(format, attribute, ap);
	return (formatlen);
}
