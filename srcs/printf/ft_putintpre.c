/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintpre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:52:10 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 09:28:00 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putfmtdi
**
** 精度指定を考慮した数字出力
** -----------------------------------------------------------------------------
*/

void	ft_putintpre(t_fmt attribute, long num)
{
	if (attribute.precision == 0 && num == 0)
		return ;
	if (attribute.sign)
		ft_putchar_fd(attribute.sign, STDOUT);
	if (attribute.precision > (int)ft_numlen(num, attribute.base))
		ft_putpad(attribute.precision -
					(int)ft_numlen(num, attribute.base), '0');
	if (num == (long)INT_MIN * (-1))
		ft_putstr_fd("2147483648", STDOUT);
	else
		ft_putnbr_fd((int)num, STDOUT);
}
