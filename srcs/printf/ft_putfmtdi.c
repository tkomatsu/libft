/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmtdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:57:04 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/16 19:49:38 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putconvert
**
** put formatted integer and return output length
**
** フラグ対応
**   '-': 左づめ対応。attribute.minus == 1の場合対応
**   '0': フィールドの空白(padding)を0にする。
**        '-'フラグがついている場合無視。
**
** フィールド対応
**   attribute.field > integer lengthの時(負の値の際の'-'を含む)
**   1. attribute.minus == 1の時
**     paddingを数字の頭につける
**   2. attribute.minus == 0の時
**     paddingを数字の末尾につける
**
** 精度対応
**   表示される最小の桁数の指定。指定された桁数は必ず出力する。桁数に符号は含めない。
**   変換後の値が指定された桁数に足りない場合、左側が0で埋められる。
**   attribute.precision == -1の時、精度指定は1とする。
**
** -----------------------------------------------------------------------------
*/

static long		my_getsign(va_list ap, t_fmt *attribute)
{
	long num;

	num = (long)va_arg(ap, int);
	if (num < 0)
	{
		attribute->sign = '-';
		num *= -1;
	}
	return (num);
}

static size_t	my_getintlen(t_fmt attribute, long num)
{
	size_t	nlen;

	nlen = ft_numlen(num, attribute.base);
	if (attribute.precision > (int)nlen)
		nlen = attribute.precision;
	if (attribute.sign)
		nlen += 1;
	if (attribute.precision == 0 && num == 0)
		nlen = 0;
	if (attribute.field > (int)nlen)
		nlen = attribute.field;
	return (nlen);
}

size_t			ft_putfmtdi(t_fmt attribute, va_list ap)
{
	long	num;
	size_t	len;

	len = 0;
	num = my_getsign(ap, &attribute);
	len = my_getintlen(attribute, num);
	if ((attribute.zero && attribute.minus) || attribute.precision >= 0)
		attribute.zero = 0;
	if (attribute.field && attribute.precision == -1 &&
		attribute.sign && attribute.zero)
	{
		attribute.precision = attribute.field - 1;
		attribute.field = 0;
	}
	if (attribute.minus == 0)
		ft_putintpad(attribute, num);
	ft_putintpre(attribute, num);
	if (attribute.minus)
		ft_putintpad(attribute, num);
	return (len);
}
