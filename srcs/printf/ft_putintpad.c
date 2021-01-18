/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:01:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/16 15:12:53 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putfmtdi, ft_putfmtux
**
** put padding the length of (field - num)
** -----------------------------------------------------------------------------
*/

void	ft_putintpad(t_fmt attribute, long num)
{
	int		nlen;
	char	pad;

	pad = (attribute.zero ? '0' : ' ');
	nlen = (int)ft_numlen(num, attribute.base);
	if (attribute.precision > nlen)
	{
		nlen = attribute.precision;
		pad = ' ';
	}
	if (attribute.sign)
		nlen++;
	if (attribute.precision == 0 && num == 0)
		nlen = 0;
	if (attribute.field > nlen)
	{
		if (attribute.precision > 0)
			pad = ' ';
		ft_putpad(attribute.field - nlen, pad);
	}
}
