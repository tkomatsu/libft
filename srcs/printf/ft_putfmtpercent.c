/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmtpercent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:55:46 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 09:26:39 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putconvert
**
** put formatted percent and return output length
** -----------------------------------------------------------------------------
*/

size_t	ft_putfmtpercent(t_fmt attribute)
{
	char	pad;

	if (attribute.zero && attribute.minus)
		attribute.zero = 0;
	pad = (attribute.zero ? '0' : ' ');
	if (attribute.field)
	{
		if (attribute.minus == 0)
			ft_putpad(attribute.field - 1, pad);
		ft_putchar_fd('%', STDOUT);
		if (attribute.minus)
			ft_putpad(attribute.field - 1, pad);
		return ((size_t)attribute.field);
	}
	ft_putchar_fd('%', STDOUT);
	return (1);
}
