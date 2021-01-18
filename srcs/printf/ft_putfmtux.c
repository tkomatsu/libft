/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmtux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:57:04 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/16 20:11:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putconvert
**
** put formatted unsigned integer and return output length
**
** 1. フラグ対応
**   '-': 左づめ対応。attribute.minus == 1の場合対応
**   '0': フィールドの空白を0にする
**
** 2. フィールド対応
**
** 3. 精度対応
**
** -----------------------------------------------------------------------------
*/

static size_t	my_getintlen(t_fmt attribute, unsigned int num)
{
	size_t	nlen;

	nlen = ft_numlen(num, attribute.base);
	if (attribute.precision > (int)nlen)
		nlen = attribute.precision;
	if (attribute.precision == 0 && num == 0)
		nlen = 0;
	if (attribute.field > (int)nlen)
		nlen = attribute.field;
	return (nlen);
}

static void		my_putnbr_bs(t_fmt attribute, unsigned int n)
{
	char	*symbols;

	if (n >= (unsigned int)attribute.base)
		my_putnbr_bs(attribute, n / attribute.base);
	symbols = "0123456789abcdef";
	if (attribute.capital)
		ft_putchar_fd(ft_toupper(symbols[n % attribute.base]), 1);
	else
		ft_putchar_fd(symbols[n % attribute.base], 1);
}

static void		my_putintpre(t_fmt attribute, unsigned int num)
{
	if (attribute.precision == 0 && num == 0)
		return ;
	if (attribute.sign)
		ft_putchar_fd(attribute.sign, 1);
	if (attribute.precision > (int)ft_numlen(num, attribute.base))
		ft_putpad(attribute.precision -
					(int)ft_numlen(num, attribute.base), '0');
	if (num == 0)
		ft_putchar_fd('0', 1);
	else
		my_putnbr_bs(attribute, num);
}

size_t			ft_putfmtux(t_fmt attribute, va_list ap, char conv)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (conv == 'x' || conv == 'X')
		attribute.base = 16;
	if (conv == 'X')
		attribute.capital = 1;
	if ((attribute.zero && attribute.minus) || attribute.precision >= 0)
		attribute.zero = 0;
	if (attribute.minus == 0)
		ft_putintpad(attribute, num);
	my_putintpre(attribute, num);
	if (attribute.minus)
		ft_putintpad(attribute, num);
	return (my_getintlen(attribute, num));
}
