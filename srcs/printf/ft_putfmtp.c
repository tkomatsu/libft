/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmtp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:57:04 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/16 20:11:37 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putconvert
**
** put formatted pointer and return output length
**
** 1. フラグ対応
**   '-': 左づめ対応。attribute.minus == 1の場合対応
**   '0': フィールドの空白を0にする
**   両方ついていた場合、'0'フラグを無視
**
** 2. フィールド対応
**   全体の出力の幅を指定する
**   ポインタの出力より短い場合は無視
**
** 3. 精度対応
**   0指定の場合数字部分の出力をしない
**   それ以外の指定があった場合精度指定数分数字を出力
**
** -----------------------------------------------------------------------------
*/

static size_t	my_getptrlen(t_fmt attribute, unsigned long ptr)
{
	size_t	nlen;

	nlen = ft_numlen(ptr, attribute.base);
	if (attribute.precision > (int)nlen)
		nlen = attribute.precision;
	if (attribute.precision == 0)
		nlen = 0;
	nlen += 2;
	if (attribute.field > (int)nlen)
		nlen = attribute.field;
	return (nlen);
}

static void		my_putnbr_bs(t_fmt attribute, unsigned long n)
{
	char	*symbols;

	if (n >= (unsigned long)attribute.base)
		my_putnbr_bs(attribute, n / attribute.base);
	symbols = "0123456789abcdef";
	if (attribute.capital)
		ft_putchar_fd(ft_toupper(symbols[n % attribute.base]), 1);
	else
		ft_putchar_fd(symbols[n % attribute.base], 1);
}

static void		my_putptrpre(t_fmt attribute, unsigned long num)
{
	if (attribute.precision == 0)
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

static void		my_putptrpad(t_fmt attribute, unsigned long num)
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
	if (attribute.precision == 0)
		nlen = 0;
	nlen += 2;
	if (attribute.field > nlen)
	{
		if (attribute.precision > 0)
			pad = ' ';
		ft_putpad(attribute.field - nlen, pad);
	}
}

size_t			ft_putfmtp(t_fmt attribute, va_list ap)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(ap, void*);
	attribute.base = 16;
	if (attribute.zero && attribute.minus)
		attribute.zero = 0;
	if (attribute.minus == 0)
		my_putptrpad(attribute, ptr);
	ft_putstr_fd("0x", 1);
	my_putptrpre(attribute, ptr);
	if (attribute.minus)
		my_putptrpad(attribute, ptr);
	return (my_getptrlen(attribute, ptr));
}
